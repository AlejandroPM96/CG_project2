#pragma once
class Cube
{
public:
	Cube();
	float scale_x;
	float scale_y;
	float scale_z;
	float pos_x;
	float pos_y;
	float pos_z;
	float rot_x;
	float rot_y;
	float rot_z;
	float r;
	float g;
	float b;
	void setColor(float _r, float _g, float _b);
	void setScale(float x, float y, float z);
	void setPosition(float x, float y, float z);
	void setRotation(float x, float y, float z);
	void update();
	void draw();
};

