#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxFreeMapping.h"
#include "ofxOMXPlayer.h"
//--------------------------------------------------------------
class ofApp : public ofBaseApp
{    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);	    
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

private:
    ofxFreeMapping mScreens[1];
    ofxOMXPlayer mOMXPlayer;
    ofxPanel gui;
    
    int mMappersCount;    
    bool mShowConfiguration;
};

