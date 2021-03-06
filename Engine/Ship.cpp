#include "Ship.h"
#include <math.h>

# define M_PI 3.14159f


Ship::Ship(const Vec2& in_pos, const Vec2& in_vel, const Vec2& in_acc)
	:
	pos(in_pos),
	vel(in_vel),
	acc(in_acc)
{
}

void Ship::Draw(Graphics& gfx) const
{
	gfx.DrawTriangle( pos.x + size*cosf(rotation), pos.y - size*sinf(rotation),
		pos.x + size * cosf(rotation + 0.75f*M_PI), pos.y - size * sinf(rotation + 0.75f*M_PI),
		pos.x + size * cosf(rotation + 1.25f*M_PI), pos.y - size * sinf(rotation + 1.25f*M_PI),
		color);
}


void Ship::DrawPropulsion(Graphics & gfx) const
{
	gfx.DrawLine(pos.x + (size - 2.0f) * cosf(rotation + 0.8f*M_PI), pos.y - (size - 2.0f) * sinf(rotation + 0.8f*M_PI),
		pos.x + (size + 8.0f) * cosf(rotation + 0.92f*M_PI), pos.y - (size + 8.0f) * sinf(rotation + 0.92f*M_PI), propColor);
	gfx.DrawLine(pos.x + (size - 2.0f) * cosf(rotation + 1.2f*M_PI), pos.y - (size - 2.0f) * sinf(rotation + 1.2f*M_PI),
		pos.x + (size + 8.0f) * cosf(rotation + 1.08f*M_PI), pos.y - (size + 8.0f) * sinf(rotation + 1.08f*M_PI), propColor);
}

void Ship::Reset(const Vec2 & in_pos, const Vec2 & in_vel, const Vec2 & in_acc)
{
	pos.x = in_pos.x;
	pos.y = in_pos.y;
	vel.x = in_vel.x;
	vel.y = in_vel.y;
	acc.x = in_acc.x;
	acc.y = in_acc.y;
}

void Ship::SetAcc(Vec2 vec)
{
	acc.x = vec.x;
	acc.y = vec.y;
}

Vec2 Ship::GetPos() const
{
	return pos;
}

float Ship::GetRotation() const
{
	return rotation;
}

float Ship::GetSize() const
{
	return size;
}

void Ship::Accelerate()
{
	if (acc.x*acc.x + acc.y*acc.y < 100000)
	{
		acc += Vec2(15.0f * cosf(rotation), -15.0f * sinf(rotation));
	}
	else
	{
		acc = Vec2(0.0f, 0.0f);
	}
	
}
void Ship::Friction()
{
	vel *= 0.99f;
}
void Ship::Update(float dt, const Graphics& gfx)
{
	
	vel += acc*dt;
	pos += vel*dt;
	float width = gfx.ScreenWidth;
	float height = gfx.ScreenHeight;
	if (pos.x < 0.0f) {
		pos.x = width - 1.0f + pos.x;
	}
	else if (pos.x >= width) {
		pos.x -= width;
	}
	if (pos.y < 0.0f) {
		pos.y = height - 1.0f + pos.y;
	}
	else if (pos.y >= height) {
		pos.y -= height;
	}
}

void Ship::Rotate(const float & angle)
{
	rotation += angle;
	if (rotation < 0.0f) {
		rotation += 2 * M_PI;
	}
	else if (rotation >= 2 * M_PI) {
		rotation -= 2 * M_PI;
	}
}

