
#include <mutex>
#include <thread>

#include "Interface/Context/Context.h"

#include "Common/NetStream.h"

namespace FEXCore {

class GdbServer {
public:
    GdbServer(FEXCore::Context::Context *ctx);

private:
    void Break();

    std::unique_ptr<std::iostream> OpenSocket();
    void StartThread();
    void GdbServerLoop();
    std::string ReadPacket(std::iostream &stream);
    void SendPacket(std::ostream &stream, std::string packet);

    std::string ProcessPacket(std::string &packet);
    std::string handleQuery(std::string &packet);
    std::string handleXfer(std::string &packet);
    std::string handleMemory(std::string &packet);
    std::string handleV(std::string& packet);

    std::string readRegs();

    FEXCore::Context::Context *CTX;
    std::thread gdbServerThread;
    uint64_t data_offset;
    std::unique_ptr<std::iostream> CommsStream;
    std::mutex sendMutex;
};

}



