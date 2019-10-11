
#include <string>

#include <zlib.h>

namespace ZLibUtil
{
    class ZlibUtil 
    {
        public:
            static const int BEST_COMPRESSIOn = Z_BEST_COMPRESSION; 
            std::string compressString(const std::string& str, int compressionlevel);
    };

}
