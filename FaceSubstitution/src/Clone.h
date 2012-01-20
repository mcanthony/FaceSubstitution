#pragma once

#include "ofMain.h"

class Clone {
public:
	void setup(int width, int height);
	void setStrength(int strength);
	void update(ofTexture& src, ofTexture& dst, ofTexture& mask);
	void draw(float x, float y);
	void draw(float x, float y, float w, float h);
	
	ofTexture & getTextureRef();
	void readToPixels(ofPixels & pix);

protected:
	void maskedBlur(ofTexture& tex, ofTexture& mask, ofFbo& result);
	ofFbo buffer, srcBlur, dstBlur;
	ofShader maskBlurShader, cloneShader;
	int strength;
};