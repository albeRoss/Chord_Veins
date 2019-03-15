//
// Generated file, do not edit! Created by nedtool 5.2 from veins/modules/messages/StableMessage.msg.
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
#include "StableMessage_m.h"

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

Register_Class(StableMessage)

StableMessage::StableMessage(const char *name, short kind) : ::WaveShortMessage(name,kind)
{
    this->countNode = 0;
    this->firstNodeSender = 0;
    this->successor = 0;
    this->isStable = false;
    this->id = 0;
    this->chordName = "";
    this->startTime = 0.0;
    this->ringDelay = 0.0;
}

StableMessage::StableMessage(const StableMessage& other) : ::WaveShortMessage(other)
{
    copy(other);
}

StableMessage::~StableMessage()
{
}

StableMessage& StableMessage::operator=(const StableMessage& other)
{
    if (this==&other) return *this;
    ::WaveShortMessage::operator=(other);
    copy(other);
    return *this;
}

void StableMessage::copy(const StableMessage& other)
{
    this->countNode = other.countNode;
    this->firstNodeSender = other.firstNodeSender;
    this->successor = other.successor;
    this->isStable = other.isStable;
    this->id = other.id;
    this->chordName = other.chordName;
    this->startTime = other.startTime;
    this->ringDelay = other.ringDelay;
}

void StableMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::WaveShortMessage::parsimPack(b);
    doParsimPacking(b,this->countNode);
    doParsimPacking(b,this->firstNodeSender);
    doParsimPacking(b,this->successor);
    doParsimPacking(b,this->isStable);
    doParsimPacking(b,this->id);
    doParsimPacking(b,this->chordName);
    doParsimPacking(b,this->startTime);
    doParsimPacking(b,this->ringDelay);
}

void StableMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::WaveShortMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->countNode);
    doParsimUnpacking(b,this->firstNodeSender);
    doParsimUnpacking(b,this->successor);
    doParsimUnpacking(b,this->isStable);
    doParsimUnpacking(b,this->id);
    doParsimUnpacking(b,this->chordName);
    doParsimUnpacking(b,this->startTime);
    doParsimUnpacking(b,this->ringDelay);
}

int StableMessage::getCountNode() const
{
    return this->countNode;
}

void StableMessage::setCountNode(int countNode)
{
    this->countNode = countNode;
}

int StableMessage::getFirstNodeSender() const
{
    return this->firstNodeSender;
}

void StableMessage::setFirstNodeSender(int firstNodeSender)
{
    this->firstNodeSender = firstNodeSender;
}

int StableMessage::getSuccessor() const
{
    return this->successor;
}

void StableMessage::setSuccessor(int successor)
{
    this->successor = successor;
}

bool StableMessage::getIsStable() const
{
    return this->isStable;
}

void StableMessage::setIsStable(bool isStable)
{
    this->isStable = isStable;
}

int StableMessage::getId() const
{
    return this->id;
}

void StableMessage::setId(int id)
{
    this->id = id;
}

const char * StableMessage::getChordName() const
{
    return this->chordName.c_str();
}

void StableMessage::setChordName(const char * chordName)
{
    this->chordName = chordName;
}

double StableMessage::getStartTime() const
{
    return this->startTime;
}

void StableMessage::setStartTime(double startTime)
{
    this->startTime = startTime;
}

double StableMessage::getRingDelay() const
{
    return this->ringDelay;
}

void StableMessage::setRingDelay(double ringDelay)
{
    this->ringDelay = ringDelay;
}

class StableMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    StableMessageDescriptor();
    virtual ~StableMessageDescriptor();

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

Register_ClassDescriptor(StableMessageDescriptor)

StableMessageDescriptor::StableMessageDescriptor() : omnetpp::cClassDescriptor("StableMessage", "WaveShortMessage")
{
    propertynames = nullptr;
}

StableMessageDescriptor::~StableMessageDescriptor()
{
    delete[] propertynames;
}

bool StableMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<StableMessage *>(obj)!=nullptr;
}

const char **StableMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *StableMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int StableMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int StableMessageDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *StableMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "countNode",
        "firstNodeSender",
        "successor",
        "isStable",
        "id",
        "chordName",
        "startTime",
        "ringDelay",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int StableMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "countNode")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "firstNodeSender")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "successor")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "isStable")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "chordName")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "startTime")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "ringDelay")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *StableMessageDescriptor::getFieldTypeString(int field) const
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
        "bool",
        "int",
        "string",
        "double",
        "double",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **StableMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *StableMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int StableMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    StableMessage *pp = (StableMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *StableMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    StableMessage *pp = (StableMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string StableMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    StableMessage *pp = (StableMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCountNode());
        case 1: return long2string(pp->getFirstNodeSender());
        case 2: return long2string(pp->getSuccessor());
        case 3: return bool2string(pp->getIsStable());
        case 4: return long2string(pp->getId());
        case 5: return oppstring2string(pp->getChordName());
        case 6: return double2string(pp->getStartTime());
        case 7: return double2string(pp->getRingDelay());
        default: return "";
    }
}

bool StableMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    StableMessage *pp = (StableMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setCountNode(string2long(value)); return true;
        case 1: pp->setFirstNodeSender(string2long(value)); return true;
        case 2: pp->setSuccessor(string2long(value)); return true;
        case 3: pp->setIsStable(string2bool(value)); return true;
        case 4: pp->setId(string2long(value)); return true;
        case 5: pp->setChordName((value)); return true;
        case 6: pp->setStartTime(string2double(value)); return true;
        case 7: pp->setRingDelay(string2double(value)); return true;
        default: return false;
    }
}

const char *StableMessageDescriptor::getFieldStructName(int field) const
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

void *StableMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    StableMessage *pp = (StableMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


