#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <iostream>
#include <chrono>

int main(void) {
    auto sequenceFile = fopen("../ntsc2vuy720x480.yuv", "rb");
    int frameSize = 720 * 480 * 2;

    fseek(sequenceFile, 0, SEEK_END);
    int frameCount = ftell(sequenceFile) / frameSize;

    int frameIndex = 0;

    // ソケット作成
    int sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "socket" << std::endl;
        return 1;
    }

    // struct sockaddr_un 作成
    struct sockaddr_un sa = {0};
    sa.sun_family = AF_UNIX;
    strcpy(sa.sun_path, "/tmp/vcam-socket");

    try {
        // 接続
        if (connect(sock, (struct sockaddr*) &sa, sizeof(struct sockaddr_un)) == -1) {
            throw std::runtime_error("connect");
        }

        uint8_t* framebuffer = new uint8_t[frameSize];

        while (true) {
            usleep(1000 * 1000 / 30);

            fseek(sequenceFile, (frameIndex % frameCount) * frameSize, SEEK_SET);
            fread(framebuffer, 1, frameSize, sequenceFile);
            ++frameIndex;

            // 送信
            if (write(sock, framebuffer, frameSize) == -1) {
                throw std::runtime_error("write");
            }
        }
    } catch (const std::exception& e) {
        std::cerr << e.what();
        close(sock);
        return 1;
    }

    // クローズ
    close(sock);
    return 0;
}
