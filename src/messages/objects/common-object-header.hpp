#ifndef __MESSAGE_OBJECTS_COMMON_OBJECT_HEADER_HPP__
#define __MESSAGE_OBJECTS_COMMON_OBJECT_HEADER_HPP__

/**
 * @brief Values for Object-Class field in CommonObjectHeader
 */
enum ObjectClass {
    OBJ_CLS_RESERVED = 0,
    /** @see https://datatracker.ietf.org/doc/html/rfc5440#section-7.3 */
    OBJ_CLS_OPEN = 1,
    OBJ_CLS_RP,
    OBJ_CLS_NO_PATH,
    OBJ_CLS_END_POINTS,
    OBJ_CLS_BANDWIDTH,
    OBJ_CLS_METRIC,
    OBJ_CLS_ERO,
    OBJ_CLS_RRO,
    OBJ_CLS_LSPA,
    OBJ_CLS_IRO,
    OBJ_CLS_SVEC,
    OBJ_CLS_NOTIFICATION,
    OBJ_CLS_PCEP_ERROR,
    OBJ_CLS_LOAD_BALANCING,
    OBJ_CLS_CLOSE,
    OBJ_CLS_PATH_KEY,
    OBJ_CLS_XRO,
    // OBJ_CLS_UNASSIGNED,
    OBJ_CLS_MONITORING,
    OBJ_CLS_PCC_REQ_ID,
    OBJ_CLS_OF,
    OBJ_CLS_CLASSTYPE,
    // OBJ_CLS_UNASSIGNED,
    OBJ_CLS_GLOBAL_CONSTRAINTS,
    OBJ_CLS_PCE_ID,
    OBJ_CLS_PROC_TIME,
    OBJ_CLS_OVERLOAD,
    OBJ_CLS_UNREACH_DESTINATION,
    OBJ_CLS_SERO,
    OBJ_CLS_SRRO,
    OBJ_CLS_BNC,
    OBJ_CLS_LSP,
    OBJ_CLS_SRP,
    OBJ_CLS_VENDOR_INFORMATION,
    OBJ_CLS_BU,
    OBJ_CLS_INTER_LAYER,
    OBJ_CLS_SWITCH_LAYER,
    OBJ_CLS_REQ_ADAP_CAP,
    OBJ_CLS_SERVER_INDICATION,
    OBJ_CLS_ASSOCIATION,
    OBJ_CLS_S2LS,
    OBJ_CLS_WA,
    OBJ_CLS_FLOWSPEC,
    OBJ_CLS_CCI_OBJECT_TYPE,
    OBJ_CLS_PATH_ATTRIB,
    // OBJ_CLS_UNASSIGNED,
    OBJ_CLS_EXPERIMENTAL
};

#define P_FLAG 0x02
#define I_FLAG 0x01

/**
 * @brief Common object header
 * Encoded message:
 *
 *   0                   1                   2                   3
 *   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  | Object-Class  |   OT  |Res|P|I|   Object Length (bytes)       |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  |                                                               |
 *  //                        (Object body)                        //
 *  |                                                               |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *
 * @see https://datatracker.ietf.org/doc/html/rfc5440#section-7.2
 */

class CommonObjectHeader {
protected:
    ObjectClass objectClass;
    uint8_t objectType;
    uint8_t flags;
    uint16_t messageLength;
public:
    CommonObjectHeader(
        ObjectClass objClass,
        uint8_t objType
    );
    virtual ~CommonObjectHeader();

    void setP(bool status) { status ? setP() : clearP(); };
    inline void setP() { flags |= P_FLAG; };
    inline void clearP() { flags &= ~P_FLAG; };
    inline bool isP() { return (flags & P_FLAG) != 0; };
    void setI(bool status) { status ? setP() : clearP(); };
    inline void setI() { flags |= I_FLAG; };
    inline void clearI() { flags &= ~I_FLAG; };
    inline bool isI() { return (flags & I_FLAG) != 0; };

    void updateMessageLength(uint16_t length);

    return_t marshall(std::vector<byte> *out);
    return_t unmarshall(std::vector<byte> *out, uint16_t *offset);
    friend std::ostream& operator<<(std::ostream &out, const CommonObjectHeader &obj);
};

#endif // __MESSAGE_OBJECTS_COMMON_OBJECT_HEADER_HPP__