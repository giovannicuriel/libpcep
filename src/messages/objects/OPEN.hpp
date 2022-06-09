#ifndef __MESSAGES_OBJECTS_OPEN_HPP__
#define __MESSAGES_OBJECTS_OPEN_HPP__

#include "./common-object-header.hpp"

class OPENObject {
protected:
    CommonObjectHeader header;
    Version ver;
    uint8_t flags;
    uint8_t keepAlive;
    uint8_t deadTimer;
    uint8_t sid;
public:
    OPENObject(
        uint8_t keepAlive,
        uint8_t deadTimer,
        uint8_t sid,
        Version version = VERSION_ONE,
        uint8_t flags = 0
    )
    virtual ~OPENObject();

    void updateMessageLength(uint16_t length);

    return_t marshall(std::vector<byte> *out);
    return_t unmarshall(std::vector<byte> *out, uint16_t *offset);
    friend std::ostream& operator<<(std::ostream &out, const OPENObject &obj);


    /**
     * Values for Ver field in CommonHeader
     */
    enum Version {
      VERSION_ONE = 1,  //!< ONE
    };
};

#endif // __MESSAGES_OBJECTS_OPEN_HPP__