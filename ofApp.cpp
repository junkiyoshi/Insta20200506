#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	int radius = 300;

	for (int i = 0; i < 5; i++) {

		vector<glm::vec2> vertices;
		for (float deg = 0; deg < 360; deg += 0.3) {

			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			auto noise_value = ofNoise(glm::vec4(i, location * 0.05, ofGetFrameNum() * 0.005));
			location *= noise_value > 0.4 ? noise_value : 0.4;

			vertices.push_back(location);
		}

		ofFill();
		ofSetColor(39, ofMap(i, 0, 5, 32, 255));
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);

		ofNoFill();
		ofSetColor(239, ofMap(i, 0, 5, 32, 255));
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);
	}
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}