#include "Enemy.h"


void Enemy::setEnemyHealth(int inEnemyHealth) {
	this->enemyHealth = inEnemyHealth;
}
int Enemy::getEnemyHealth() {
	return this->enemyHealth;
}
void Enemy::setEnemySpeed(int inEnemySpeed) {
	this->enemySpeed = inEnemySpeed;
}
int Enemy::getEnemySpeed() {
	return this->enemySpeed;
}
void Enemy::setEnemyPos(Vector2 inEnemyPos) {
	this->enemyPos = inEnemyPos;
}
Vector2 Enemy::getEnemyPos() {
	return enemyPos;
}
void Enemy::setEnemyAliveState(bool inAliveState) {
	this->isAlive = inAliveState;
}
bool Enemy::getEnemyAliveState() {
	return this->isAlive;
}
void Enemy::setEnemyTecture(Texture2D inEnemyTexture) {
	this->enemyTexture = inEnemyTexture;
}


void Enemy::movementToPlayer() {
	
}
