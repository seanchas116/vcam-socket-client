# vcam-socket-client

Send frame data to [virtual camera](https://github.com/seanchas116/CoreMediaIO-DAL-Example/tree/vcam-socket) via socket

## How to run

### Virtual camera

* Clone https://github.com/seanchas116/CoreMediaIO-DAL-Example/tree/vcam-socket
* Open `/BuildSystem/XcodeProjects/Sample.xcodeproj`
* Build target "SampleVCam Plugin"
* Copy `SampleVCam.plugin` to `/Library/CoreMediaIO/Plug-Ins/DAL`
* Run `SampleVCamAssistant` (this is the server)

### Client

```
git clone git@github.com:seanchas116/vcam-socket-client.git
cd vcam-socket-client
mkdir build
cd build
cmake ..
make
./vcam-socket-client
```
