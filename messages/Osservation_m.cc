//
// Generated file, do not edit! Created by nedtool 5.2 from veins/modules/messages/Osservation.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "Osservation_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(Osservation)

Osservation::Osservation(const char *name, short kind) : ::WaveShortMessage(name,kind)
{
    this->firstSender = 0;
    this->senderOs = 0;
    this->receiverOs = 0;
    this->kind = 0;
    this->id = 0;
    this->isValidate = false;
    this->blockValidated = false;
    this->sequenceNumber = 0;
    this->chordName = "";
    this->isFirstSend = false;
    this->isLastHop = false;
}

Osservation::Osservation(const Osservation& other) : ::WaveShortMessage(other)
{
    copy(other);
}

Osservation::~Osservation()
{
}

Osservation& Osservation::operator=(const Osservation& other)
{
    if (this==&other) return *this;
    ::WaveShortMessage::operator=(other);
    copy(other);
    return *this;
}

void Osservation::copy(const Osservation& other)
{
    this->firstSender = other.firstSender;
    this->senderOs = other.senderOs;
    this->receiverOs = other.receiverOs;
    this->kind = other.kind;
    this->id = other.id;
    this->info = other.info;
    this->isValidate = other.isValidate;
    this->blockValidated = other.blockValidated;
    this->sequenceNumber = other.sequenceNumber;
    this->chordName = other.chordName;
    this->isFirstSend = other.isFirstSend;
    this->isLastHop = other.isLastHop;
}

void Osservation::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::WaveShortMessage::parsimPack(b);
    doParsimPacking(b,this->firstSender);
    doParsimPacking(b,this->senderOs);
    doParsimPacking(b,this->receiverOs);
    doParsimPacking(b,this->kind);
    doParsimPacking(b,this->id);
    doParsimPacking(b,this->info);
    doParsimPacking(b,this->isValidate);
    doParsimPacking(b,this->blockValidated);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->chordName);
    doParsimPacking(b,this->isFirstSend);
    doParsimPacking(b,this->isLastHop);
}

void Osservation::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::WaveShortMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->firstSender);
    doParsimUnpacking(b,this->senderOs);
    doParsimUnpacking(b,this->receiverOs);
    doParsimUnpacking(b,this->kind);
    doParsimUnpacking(b,this->id);
    doParsimUnpacking(b,this->info);
    doParsimUnpacking(b,this->isValidate);
    doParsimUnpacking(b,this->blockValidated);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->chordName);
    doParsimUnpacking(b,this->isFirstSend);
    doParsimUnpacking(b,this->isLastHop);
}

int Osservation::getFirstSender() const
{
    return this->firstSender;
}

void Osservation::setFirstSender(int firstSender)
{
    this->firstSender = firstSender;
}

int Osservation::getSenderOs() const
{
    return this->senderOs;
}

void Osservation::setSenderOs(int senderOs)
{
    this->senderOs = senderOs;
}

int Osservation::getReceiverOs() const
{
    return this->receiverOs;
}

void Osservation::setReceiverOs(int receiverOs)
{
    this->receiverOs = receiverOs;
}

int Osservation::getKind() const
{
    return this->kind;
}

void Osservation::setKind(int kind)
{
    this->kind = kind;
}

int Osservation::getId() const
{
    return this->id;
}

void Osservation::setId(int id)
{
    this->id = id;
}

const char * Osservation::getInfo() const
{
    return this->info.c_str();
}

void Osservation::setInfo(const char * info)
{
    this->info = info;
}

bool Osservation::getIsValidate() const
{
    return this->isValidate;
}

void Osservation::setIsValidate(bool isValidate)
{
    this->isValidate = isValidate;
}

bool Osservation::getBlockValidated() const
{
    return this->blockValidated;
}

void Osservation::setBlockValidated(bool blockValidated)
{
    this->blockValidated = blockValidated;
}

double Osservation::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void Osservation::setSequenceNumber(double sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

const char * Osservation::getChordName() const
{
    return this->chordName.c_str();
}

void Osservation::setChordName(const char * chordName)
{
    this->chordName = chordName;
}

bool Osservation::getIsFirstSend() const
{
    return this->isFirstSend;
}

void Osservation::setIsFirstSend(bool isFirstSend)
{
    this->isFirstSend = isFirstSend;
}

bool Osservation::getIsLastHop() const
{
    return this->isLastHop;
}

void Osservation::setIsLastHop(bool isLastHop)
{
    this->isLastHop = isLastHop;
}

class OsservationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OsservationDescriptor();
    virtual ~OsservationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OsservationDescriptor)

OsservationDescriptor::OsservationDescriptor() : omnetpp::cClassDescriptor("Osservation", "WaveShortMessage")
{
    propertynames = nullptr;
}

OsservationDescriptor::~OsservationDescriptor()
{
    delete[] propertynames;
}

bool OsservationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Osservation *>(obj)!=nullptr;
}

const char **OsservationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OsservationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OsservationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int OsservationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *OsservationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "firstSender",
        "senderOs",
        "receiverOs",
        "kind",
        "id",
        "info",
        "isValidate",
        "blockValidated",
        "sequenceNumber",
        "chordName",
        "isFirstSend",
        "isLastHop",
    };
    return (field>=0 && field<12) ? fieldNames[field] : nullptr;
}

int OsservationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "firstSender")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderOs")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "receiverOs")==0) return base+2;
    if (fieldName[0]=='k' && strcmp(fieldName, "kind")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "info")==0) return base+5;
    if (fieldName[0]=='i' && strcmp(fieldName, "isValidate")==0) return base+6;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockValidated")==0) return base+7;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+8;
    if (fieldName[0]=='c' && strcmp(fieldName, "chordName")==0) return base+9;
    if (fieldName[0]=='i' && strcmp(fieldName, "isFirstSend")==0) return base+10;
    if (fieldName[0]=='i' && strcmp(fieldName, "isLastHop")==0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OsservationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "string",
        "bool",
        "bool",
        "double",
        "string",
        "bool",
        "bool",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : nullptr;
}

const char **OsservationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OsservationDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OsservationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Osservation *pp = (Osservation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *OsservationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Osservation *pp = (Osservation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OsservationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Osservation *pp = (Osservation *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getFirstSender());
        case 1: return long2string(pp->getSenderOs());
        case 2: return long2string(pp->getReceiverOs());
        case 3: return long2string(pp->getKind());
        case 4: return long2string(pp->getId());
        case 5: return oppstring2string(pp->getInfo());
        case 6: return bool2string(pp->getIsValidate());
        case 7: return bool2string(pp->getBlockValidated());
        case 8: return double2string(pp->getSequenceNumber());
        case 9: return oppstring2string(pp->getChordName());
        case 10: return bool2string(pp->getIsFirstSend());
        case 11: return bool2string(pp->getIsLastHop());
        default: return "";
    }
}

bool OsservationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Osservation *pp = (Osservation *)object; (void)pp;
    switch (field) {
        case 0: pp->setFirstSender(string2long(value)); return true;
        case 1: pp->setSenderOs(string2long(value)); return true;
        case 2: pp->setReceiverOs(string2long(value)); return true;
        case 3: pp->setKind(string2long(value)); return true;
        case 4: pp->setId(string2long(value)); return true;
        case 5: pp->setInfo((value)); return true;
        case 6: pp->setIsValidate(string2bool(value)); return true;
        case 7: pp->setBlockValidated(string2bool(value)); return true;
        case 8: pp->setSequenceNumber(string2double(value)); return true;
        case 9: pp->setChordName((value)); return true;
        case 10: pp->setIsFirstSend(string2bool(value)); return true;
        case 11: pp->setIsLastHop(string2bool(value)); return true;
        default: return false;
    }
}

const char *OsservationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *OsservationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Osservation *pp = (Osservation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


