#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <iostream>

#define MESSAGE "Hello World!"

int main(void)
{
    // ソケット作成
    int sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock == -1)
    {
        std::cerr << "socket" << std::endl;
        return 1;
    }

    // struct sockaddr_un 作成
    struct sockaddr_un sa = {0};
    sa.sun_family = AF_UNIX;
    strcpy(sa.sun_path, "/tmp/unix-domain-socket");

    // 接続
    if (connect(sock, (struct sockaddr*) &sa, sizeof(struct sockaddr_un)) == -1)
    {
        std::cerr << "connect" << std::endl;
        goto bail;
    }

    // 送信
    if (write(sock, MESSAGE, strlen(MESSAGE)) == -1)
    {
        std::cerr << "write" << std::endl;
        goto bail;
    }

    // クローズ
    close(sock);
    return 0;
 
bail:
    // エラーが発生した場合の処理
    close(sock);
    return 1;
}
