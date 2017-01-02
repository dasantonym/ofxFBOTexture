#include "ofMain.h"
#include "ofThread.h"

class ofxThreadedImageSaver : public ofThread, public ofImage {
public:
    string fileName;
    
    void threadedFunction() {
        if(lock()) {
            save(fileName);
            unlock();
        } else {
            printf("ofxThreadedImageSaver - cannot save %s cos I'm locked", fileName.c_str());
        }
        stopThread();
    }
    
    void saveThreaded(string fileName) {
        this->fileName = fileName;
        startThread(false); // blocking
    }
};
