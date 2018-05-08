#include "Particle.h"
#include <glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/* Particle library declaration */
namespace ParticleLibrary {
	Particle::Particle() { 
		this->autoDestruct = false;
		this->isDestroyed = false;
		this->particleTime = new Time;
		this->destructTime = 0.2f;

		this->minEnergy = 1;
		this->maxEnergy = 5;
		this->life = 1.0f;
		this->colorSize = 0;
		this->isActive = true;

		this->particlePos = Vector3::Zero;
		this->randomVelocity = Vector3::Zero;
		this->ellipsoid = Vector3::One;
		this->normal = Vector3::Zero;

		this->start = 0;
		this->end = 0;
		this->last = 0;
	}

	Particle::~Particle() { }

	void Particle::SetActiveParticle(bool active) {
		this->isActive = active;
	}

	void Particle::SetAutoDestruct(bool active) {
		this->autoDestruct = active;
	}
	
	void Particle::SetEnergy(int min, int max) {
		this->minEnergy = min;
		this->maxEnergy = max;
	}

	void Particle::SetEmission(int min, int max) {
		//this->particleCount = rand() % (max - min + 1) + min;
		this->particleCount = (min + max) * 0.5f;
		delete[] start;
		this->last = this->start = new Particle[particleCount];
		this->end = this->start + particleCount;
	}

	void Particle::SetEllipsoid(Vector3 ellipse) {
		this->ellipsoid = ellipse;
	}

	void Particle::SetEllipsoid(float x, float y, float z) {
		this->ellipsoid = Vector3(x, y, z);
	}

	void Particle::SetRandomVelocity(Vector3 randomVel) {
		this->randomVelocity = randomVel;
	}

	void Particle::SetRandomVelocity(float x, float y, float z) {
		this->randomVelocity = Vector3(x, y, z);
	}

	void Particle::SetColors(Color3* color, size_t size) {
		this->colorSize = size;
		this->colors = color;
	}

	Particle::Particle(Vector3 pos, Vector3 oppositePos, Vector3 vel,
			Vector3 randomVel, Color3 col, Vector3 norm, int minLife, int maxLife) {

		this->color = col;

		norm.X = (float)(100 - rand() % 200)/100;
		norm.Y = (float)(100 - rand() % 200)/100;
		norm.Z = (float)(100 - rand() % 200)/100;
		this->normal = norm;

		this->particlePos = pos;
		
		this->velocity = (((pos + oppositePos) * randomVel) + vel);

		if(minLife == 0 && maxLife == 0) {
			life = 0;
		}
		else {
			float tmpLife = 0.0f;
			int randVal = 0;

			if(maxLife <= 10) {
				randVal = ((maxLife * 100) * maxLife) + (maxLife * 100);
				tmpLife = (float)((maxLife * 100) - rand() % randVal)/(maxLife * 100);

				if(tmpLife < 0)
					tmpLife = -tmpLife;

				if(minLife != maxLife && tmpLife < (maxLife *  0.5f))
					tmpLife += minLife * 0.5;

				tmpLife /= 10;
			}
			this->life = tmpLife;
		}
	}

	void Particle::EmitParticles() {
		int tmpParticleCount = this->particleCount;

		if(!isActive)	tmpParticleCount = 0;
		else			tmpParticleCount = this->particleCount;

		// Check if it is auto destruct and the particle is destroyed
		if(this->autoDestruct && !this->isDestroyed) {
			if(this->particleTime->ElapsedTime() > this->destructTime) {
				// Setting active to false, it will decrease the current particle count
				if(this->isActive) {
					this->isActive = false;
				}
			}

			if(!isActive && this->curParticleCount == 0)	
				this->isDestroyed = true;
		}
		else
			this->particleTime->Reset();

		int count = (int)(tmpParticleCount/ 65);

		for(int i = 0; i != count; i++) {
			if(this->last != this->end) {

				Color3* tmpColor = new Color3;
				if(this->colorSize > 0) {
					int randIndx = rand() % this->colorSize;

					if(this->colors != 0)
						*tmpColor = this->colors[randIndx];
				}
				else {
					tmpColor[0] = Color3::White;
				}

				Vector3* randomPos = new Vector3;
				randomPos->X = (10000 - rand() % 20000)/10000.0f;
				randomPos->Y = (10000 - rand() % 20000)/10000.0f;
				randomPos->Z = (10000 - rand() % 20000)/10000.0f;

				if(IsInsideSphere(this->position, 1.0, this->position + *randomPos)) {
					this->particlePos = (*randomPos * this->ellipsoid) + this->position;
				}

				*last = Particle(this->particlePos, -this->position, this->velocity,
					this->randomVelocity, *tmpColor, this->normal, this->minEnergy, this->maxEnergy);
				last++;
			}
		}

		this->curParticleCount = last - start;
		this->UpdateParticles(0.02f);

		glVertexPointer(3, GL_FLOAT, sizeof(Particle), &start[0].particlePos);
		glColorPointer(3, GL_FLOAT, sizeof(Particle), &start[0].color);
		glNormalPointer(GL_FLOAT, sizeof(Particle), &start[0].normal);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);

		glDrawArrays(GL_POINTS, 0, last - start);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
	}

	long Particle::GetParticleCount() {
		return this->curParticleCount;
	}

	bool Particle::GetActiveParticle() {
		return this->isActive;
	}

	bool Particle::GetIsDestroyed() {
		return this->isDestroyed;
	}

	void Particle::UpdateParticles(float dt) {
		Particle* p = start;
		float decay = 0.3f;

		while(p != this->last) {
			p->life -= dt;

			if(p->life > 0) {
				p->particlePos += p->velocity * dt;
				p->color.R *= (1 - decay * dt);
				p->color.G *= (1 - decay * dt);
				p->color.B *= (1 - decay * dt);
				p++;
			}
			else {
				if(this->start != this->last) {
					*p = *(--last);
				}

				if(p >= last) return;
			}
		}
	}

	bool Particle::IsInsideSphere(Vector3 center, double radius, Vector3 pos) {
		double dx = abs(pos.X - center.X);
		double dy = abs(pos.Y - center.Y);
		double dz = abs(pos.Z - center.Z);
		
		if(dx + dy + dz <= radius)
			return true;
		
		if(dx * dx + dy * dy + dz * dz <= radius * radius)
			return true;
		
		return false;
	}
}