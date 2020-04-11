# vcam-socket-client

Send frame data to [virtual camera](https://github.com/seanchas116/CoreMediaIO-DAL-Example/tree/vcam-socket) via socket

## How to run

### Virtual camera

```
git clone git@github.com:seanchas116/CoreMediaIO-DAL-Example.git
cd CoreMediaIO-DAL-Example
git switch vcam-socket
open BuildSystem/XcodeProjects/Sample.xcodeproj
```

In Xcode, Build target "SampleVCam Plugin".
Then,

```
sudo cp BuildResults/Debug/root/Library/CoreMediaIO/Plug-Ins/DAL/SampleVCam.plugin /Library/CoreMediaIO/Plug-Ins/DAL
./BuildResults/Debug/root/Library/CoreMediaIO/Plug-Ins/DAL/SampleVCam.plugin/Contents/Resources/SampleVCamAssistant
```

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
