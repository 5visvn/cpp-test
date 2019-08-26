template<typename T>
struct Data{
   T value;
};

template<typename T>
class PushLinkNode{
public:
   PushLinkNode* next;
   PushLinkNode* pre;
private:
   T* data;
};

template<typename T>
class PopLinkNode{
public:
   PopLinkNode* next;
   PopLinkNode* pre;
private:
   T* data;
};

template<typename T>
class Link{
public:

private:
   PushLinkNode<T>* head;
   PushLinkNode<T>* tail;
   PopLinkNode<T>* head;
   PopLinkNode<T>* tail;
}
