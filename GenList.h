template <class T>
class GenList
{
public:
    virtual bool empty() const = 0;
    virtual const T front() const = 0;
    virtual const T back() const = 0;
    virtual void addFront(const T& d) = 0;
    virtual void addBack(const T& d) = 0;
    virtual void removeFront() = 0;
    virtual void removeBack() = 0;
    virtual void remove(const T& key) = 0;
    virtual int search(const T& key) const = 0;
    virtual unsigned int getSize() const = 0;  
};
