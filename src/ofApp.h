#pragma once

#define WEBCAM
//#define BLACKMAGIC
//#define CANONEDSK

#include "ofMain.h"
#include "ofxSyphon.h"
#include "ofxChromaKeyShader.h"
#include "ofxGui.h"

#ifdef CANONEDSK
#include "ofxEdsdk.h"
#endif
#ifdef BLACKMAGIC
#include "ofxBlackMagic.h"
#endif


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void resetParams(bool & b);
    
    // === Variables =============================
    
    ofImage bgImage;
    ofVideoPlayer bgMovie;
    
    bool isImage;
    bool isMovie;

    ofxChromaKeyShader *chromakey;
    int camW, camH;
    
    ofFbo checkerboardTex;
    
    ofxPanel chromaGui;
    bool bShowGui;
    bool bUpdateBgColor;
    
    ofxSyphonServer textureFinalSyphonServer;
    ofxSyphonServer textureRawSyphonServer;
    
#ifdef WEBCAM
    ofVideoGrabber camera;
#endif
#ifdef CANONEDSDK
    ofxEdsdk::Camera camera;
#endif
#ifdef BLACKMAGIC
    ofxBlackMagic camera;
#endif

};