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
# Install virtual camera plugin
sudo cp -R BuildResults/Debug/root/Library/CoreMediaIO/Plug-Ins/DAL/SampleVCam.plugin /Library/CoreMediaIO/Plug-Ins/DAL

# Run server
./BuildResults/Debug/root/Library/CoreMediaIO/Plug-Ins/DAL/SampleVCam.plugin/Contents/Resources/SampleVCamAssistant
```

Now you can see "SampleVCam" virtual camera in your favorite webcam-using app. (you'll need restarting app)

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
