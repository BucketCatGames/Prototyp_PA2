#include "Enemy.h"
#include "Player.h"


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
float Enemy::getEnemyPosX() {
	return this->enemyPos.x;
}
float Enemy::getEnemyPosY() {
	return this->enemyPos.y;
}
void Enemy::setEnemyAliveState(bool inAliveState) {
	this->isAlive = inAliveState;
}
bool Enemy::getEnemyAliveState() {
	return this->isAlive;
}
void Enemy::setEnemyTexture(Texture2D inEnemyTexture) {
	this->enemyTexture = inEnemyTexture;
}


void Enemy::movementToPlayer(Player& player) 
{
	Vector2 pos = {player.GetPlayerPosX(),player.GetPlayerPosY() };
	this->enemyMovement  = Vector2Normalize(Vector2Subtract(pos, enemyPos));  //berechnet Richtung des Vectors und normalisiert ihn
	this->enemyPos = Vector2Add(getEnemyPos(), enemyMovement);
}
void Enemy::drawEnemy() {
	DrawTexture(this->enemyTexture, enemyPos.x, enemyPos.y, WHITE);
}
void Enemy::deleteEnemyTexture()
{
	UnloadTexture(enemyTexture);
	
}


