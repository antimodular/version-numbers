#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    string xcodeMsg = ofSystem("xcode-select -p");
    ofLog()<<"xcodeMsg "<<xcodeMsg<<"@";
    string commit;
    string commitVersion;
    string versionDate;
    string versionCount;
    
    if( xcodeMsg == "" ){
        commit = "";
    }else{
        commit = ofSystem("git rev-parse --short HEAD");
        ofStringReplace(commit,"\n","");
        cout<<"git rev-parse HEAD "<<commit<<endl;
        
        versionCount = ofSystem("git rev-list HEAD --count");
        ofStringReplace(versionCount,"\n","");
        cout<<"git rev-list HEAD --count "<<versionCount<<endl;
        
        versionDate = ofSystem("git log -1 --date=short --pretty=format:%cd");
        //    string versionDate = ofSystem("git log -1 --date=short --pretty=format:%Y%m%d");
        //    string versionDate = ofSystem("git rev-list --format=format:'%ai' --max-count=1 `git rev-parse HEAD`");
        ofStringReplace(versionDate,"\n","");
        ofStringReplace(versionDate,"-","");
        ofLog()<<"versionDate "<<versionDate;
    }
    
    
    gui_main.setup();
    gui_main.setName("test");
    gui_main.setPosition(10,10);
    gui_main.add(versionLabel.setup("ver", versionString));
    gui_main.loadFromFile("gui_main.xml");
    
    ofLog()<<"saved versionString "<<versionString<<":"<<versionLabel.getParameter();
    if(commit == ""){
        ofLog()<<"app not run on developer machine. so no git info present. will use stored versionString from gui";
    }else{
        commitVersion = versionCount+" "+versionDate+" "+commit;
        versionString = commitVersion;
        versionLabel = commitVersion;
    }
    ofLog()<<"used versionString "<<versionString;
}

void ofApp::exit(){
    gui_main.saveToFile("gui_main.xml");   
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui_main.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
