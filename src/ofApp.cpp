#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{   
    ofBackground(0);
    mVideo.load("1.mp4");
    mVideo.play();
	mVideo.setSpeed(1.f);
	
	ofEnableAlphaBlending();
	ofSetFullscreen(true);
    
    mMappersCount = 1;

    for (int i = 0; i < mMappersCount; i++) 
	{
        mScreens[i].initialize(
								mVideo.getWidth(),
								mVideo.getHeight(),
                                i*100,
                                i*100
                                );
        char buf[256];
        sprintf(buf, "mapper%d.txt", i);
        mScreens[i].load(ofToDataPath(buf));
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    mVideo.update();
    
    for (int i = 0; i < mMappersCount; i++) 
	{
        mScreens[i].update();
    }    
}

//--------------------------------------------------------------
void ofApp::draw()
{    
    mScreens[0].startMapping();
    ofSetColor(255,255);
    mVideo.draw(0,0);
    mScreens[0].stopMapping();    
    
    if (mShowConfiguration) 
	{
        for (int i = 0; i < mMappersCount; i++) 
		{
            mScreens[i].drawBoundingBox();
        }

        gui.draw();
        
        ofSetColor(125, 125);
		ofFill();
        ofDrawRectangle(0, ofGetHeight() - 70, 450, 100);
        ofSetColor(255, 255);
        ofDrawBitmapString("Commands: F Fullscreen, L Load, S Save", 40, ofGetHeight() - 40);         
        ofDrawBitmapString("Press CTRL to enable/disable configuration mode", 40, ofGetHeight() - 20);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) 
{    
    switch(key)
	{
		case OF_KEY_CONTROL:
        case OF_KEY_COMMAND:
			mShowConfiguration = !mShowConfiguration;
            break;

        case 'f':
            if(mShowConfiguration)
                ofToggleFullscreen();
            break;
            
        case 'l':
            if(mShowConfiguration)
                for (int i = 0; i < mMappersCount; i++) 
				{
                    char buf[256];
                    sprintf(buf, "mapper%d.txt", i);
                    mScreens[i].load(ofToDataPath(buf));
                }
            break;

        case's':
            for (int i = 0; i < mMappersCount; i++) 
			{
                char buf[256];
                sprintf(buf, "mapper%d.txt", i);
                mScreens[i].save(ofToDataPath(buf));
            }
            break;            
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int /*button*/)
{
    for (int i = 0; i < mMappersCount; i++) {
        mScreens[i].mouseDragged(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int /*button*/)
{
    for (int i = 0; i < mMappersCount; i++) {
        mScreens[i].mousePressed(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int /*button*/)
{
    for (int i = 0; i < mMappersCount; i++) {
        mScreens[i].mouseReleased(x, y);
    }
}

