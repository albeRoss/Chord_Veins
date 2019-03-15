//
// Generated file, do not edit! Created by nedtool 5.2 from veins/modules/messages/P2PMessage.msg.
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
#include "P2PMessage_m.h"

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

Register_Class(P2PMessage)

P2PMessage::P2PMessage(const char *name, short kind) : ::WaveShortMessage(name,kind)
{
    this->kind = 0;
    this->macReqSource = 0;
    this->destinationSHA = 0;
    this->firstSourceSHA = 0;
    this->keyFindSuccessor = 0;
    this->keyNotify = 0;
    this->callerFunction = 10000;
    this->responseObj = 0;
    this->newPredecessor = 0;
    this->newSuccessor = 0;
    this->request = false;
    this->hop = 0;
}

P2PMessage::P2PMessage(const P2PMessage& other) : ::WaveShortMessage(other)
{
    copy(other);
}

P2PMessage::~P2PMessage()
{
}

P2PMessage& P2PMessage::operator=(const P2PMessage& other)
{
    if (this==&other) return *this;
    ::WaveShortMessage::operator=(other);
    copy(other);
    return *this;
}

void P2PMessage::copy(const P2PMessage& other)
{
    this->kind = other.kind;
    this->chordName = other.chordName;
    this->macReqSource = other.macReqSource;
    this->destinationSHA = other.destinationSHA;
    this->firstSourceSHA = other.firstSourceSHA;
    this->keyFindSuccessor = other.keyFindSuccessor;
    this->keyNotify = other.keyNotify;
    this->callerFunction = other.callerFunction;
    this->responseObj = other.responseObj;
    this->newPredecessor = other.newPredecessor;
    this->newSuccessor = other.newSuccessor;
    this->request = other.request;
    this->hop = other.hop;
}

void P2PMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::WaveShortMessage::parsimPack(b);
    doParsimPacking(b,this->kind);
    doParsimPacking(b,this->chordName);
    doParsimPacking(b,this->macReqSource);
    doParsimPacking(b,this->destinationSHA);
    doParsimPacking(b,this->firstSourceSHA);
    doParsimPacking(b,this->keyFindSuccessor);
    doParsimPacking(b,this->keyNotify);
    doParsimPacking(b,this->callerFunction);
    doParsimPacking(b,this->responseObj);
    doParsimPacking(b,this->newPredecessor);
    doParsimPacking(b,this->newSuccessor);
    doParsimPacking(b,this->request);
    doParsimPacking(b,this->hop);
}

void P2PMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::WaveShortMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->kind);
    doParsimUnpacking(b,this->chordName);
    doParsimUnpacking(b,this->macReqSource);
    doParsimUnpacking(b,this->destinationSHA);
    doParsimUnpacking(b,this->firstSourceSHA);
    doParsimUnpacking(b,this->keyFindSuccessor);
    doParsimUnpacking(b,this->keyNotify);
    doParsimUnpacking(b,this->callerFunction);
    doParsimUnpacking(b,this->responseObj);
    doParsimUnpacking(b,this->newPredecessor);
    doParsimUnpacking(b,this->newSuccessor);
    doParsimUnpacking(b,this->request);
    doParsimUnpacking(b,this->hop);
}

int P2PMessage::getKind() const
{
    return this->kind;
}

void P2PMessage::setKind(int kind)
{
    this->kind = kind;
}

const char * P2PMessage::getChordName() const
{
    return this->chordName.c_str();
}

void P2PMessage::setChordName(const char * chordName)
{
    this->chordName = chordName;
}

int P2PMessage::getMacReqSource() const
{
    return this->macReqSource;
}

void P2PMessage::setMacReqSource(int macReqSource)
{
    this->macReqSource = macReqSource;
}

int P2PMessage::getDestinationSHA() const
{
    return this->destinationSHA;
}

void P2PMessage::setDestinationSHA(int destinationSHA)
{
    this->destinationSHA = destinationSHA;
}

int P2PMessage::getFirstSourceSHA() const
{
    return this->firstSourceSHA;
}

void P2PMessage::setFirstSourceSHA(int firstSourceSHA)
{
    this->firstSourceSHA = firstSourceSHA;
}

int P2PMessage::getKeyFindSuccessor() const
{
    return this->keyFindSuccessor;
}

void P2PMessage::setKeyFindSuccessor(int keyFindSuccessor)
{
    this->keyFindSuccessor = keyFindSuccessor;
}

int P2PMessage::getKeyNotify() const
{
    return this->keyNotify;
}

void P2PMessage::setKeyNotify(int keyNotify)
{
    this->keyNotify = keyNotify;
}

int P2PMessage::getCallerFunction() const
{
    return this->callerFunction;
}

void P2PMessage::setCallerFunction(int callerFunction)
{
    this->callerFunction = callerFunction;
}

int P2PMessage::getResponseObj() const
{
    return this->responseObj;
}

void P2PMessage::setResponseObj(int responseObj)
{
    this->responseObj = responseObj;
}

int P2PMessage::getNewPredecessor() const
{
    return this->newPredecessor;
}

void P2PMessage::setNewPredecessor(int newPredecessor)
{
    this->newPredecessor = newPredecessor;
}

int P2PMessage::getNewSuccessor() const
{
    return this->newSuccessor;
}

void P2PMessage::setNewSuccessor(int newSuccessor)
{
    this->newSuccessor = newSuccessor;
}

bool P2PMessage::getRequest() const
{
    return this->request;
}

void P2PMessage::setRequest(bool request)
{
    this->request = request;
}

int P2PMessage::getHop() const
{
    return this->hop;
}

void P2PMessage::setHop(int hop)
{
    this->hop = hop;
}

class P2PMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    P2PMessageDescriptor();
    virtual ~P2PMessageDescriptor();

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

Register_ClassDescriptor(P2PMessageDescriptor)

P2PMessageDescriptor::P2PMessageDescriptor() : omnetpp::cClassDescriptor("P2PMessage", "WaveShortMessage")
{
    propertynames = nullptr;
}

P2PMessageDescriptor::~P2PMessageDescriptor()
{
    delete[] propertynames;
}

bool P2PMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<P2PMessage *>(obj)!=nullptr;
}

const char **P2PMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *P2PMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int P2PMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 13+basedesc->getFieldCount() : 13;
}

unsigned int P2PMessageDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<13) ? fieldTypeFlags[field] : 0;
}

const char *P2PMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "kind",
        "chordName",
        "macReqSource",
        "destinationSHA",
        "firstSourceSHA",
        "keyFindSuccessor",
        "keyNotify",
        "callerFunction",
        "responseObj",
        "newPredecessor",
        "newSuccessor",
        "request",
        "hop",
    };
    return (field>=0 && field<13) ? fieldNames[field] : nullptr;
}

int P2PMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='k' && strcmp(fieldName, "kind")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "chordName")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "macReqSource")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationSHA")==0) return base+3;
    if (fieldName[0]=='f' && strcmp(fieldName, "firstSourceSHA")==0) return base+4;
    if (fieldName[0]=='k' && strcmp(fieldName, "keyFindSuccessor")==0) return base+5;
    if (fieldName[0]=='k' && strcmp(fieldName, "keyNotify")==0) return base+6;
    if (fieldName[0]=='c' && strcmp(fieldName, "callerFunction")==0) return base+7;
    if (fieldName[0]=='r' && strcmp(fieldName, "responseObj")==0) return base+8;
    if (fieldName[0]=='n' && strcmp(fieldName, "newPredecessor")==0) return base+9;
    if (fieldName[0]=='n' && strcmp(fieldName, "newSuccessor")==0) return base+10;
    if (fieldName[0]=='r' && strcmp(fieldName, "request")==0) return base+11;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+12;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *P2PMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "bool",
        "int",
    };
    return (field>=0 && field<13) ? fieldTypeStrings[field] : nullptr;
}

const char **P2PMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *P2PMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int P2PMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    P2PMessage *pp = (P2PMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *P2PMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    P2PMessage *pp = (P2PMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string P2PMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    P2PMessage *pp = (P2PMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getKind());
        case 1: return oppstring2string(pp->getChordName());
        case 2: return long2string(pp->getMacReqSource());
        case 3: return long2string(pp->getDestinationSHA());
        case 4: return long2string(pp->getFirstSourceSHA());
        case 5: return long2string(pp->getKeyFindSuccessor());
        case 6: return long2string(pp->getKeyNotify());
        case 7: return long2string(pp->getCallerFunction());
        case 8: return long2string(pp->getResponseObj());
        case 9: return long2string(pp->getNewPredecessor());
        case 10: return long2string(pp->getNewSuccessor());
        case 11: return bool2string(pp->getRequest());
        case 12: return long2string(pp->getHop());
        default: return "";
    }
}

bool P2PMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    P2PMessage *pp = (P2PMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setKind(string2long(value)); return true;
        case 1: pp->setChordName((value)); return true;
        case 2: pp->setMacReqSource(string2long(value)); return true;
        case 3: pp->setDestinationSHA(string2long(value)); return true;
        case 4: pp->setFirstSourceSHA(string2long(value)); return true;
        case 5: pp->setKeyFindSuccessor(string2long(value)); return true;
        case 6: pp->setKeyNotify(string2long(value)); return true;
        case 7: pp->setCallerFunction(string2long(value)); return true;
        case 8: pp->setResponseObj(string2long(value)); return true;
        case 9: pp->setNewPredecessor(string2long(value)); return true;
        case 10: pp->setNewSuccessor(string2long(value)); return true;
        case 11: pp->setRequest(string2bool(value)); return true;
        case 12: pp->setHop(string2long(value)); return true;
        default: return false;
    }
}

const char *P2PMessageDescriptor::getFieldStructName(int field) const
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

void *P2PMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    P2PMessage *pp = (P2PMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


