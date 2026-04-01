/*
 * @class MyUniquePtr
 * @brief My attempt at implementing std::unique_ptr
 *
 * @tparam T the type of the managed object
 */
template<typename T>
class MyUniquePtr
{
public:
    MyUniquePtr() = default;

    ~MyUniquePtr()
    {
        delete m_ptr;
    }

    // Make class move only
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    MyUniquePtr(MyUniquePtr&& other) noexcept
        : m_ptr{ other.m_ptr }
    {
        other.m_ptr = nullptr;
    }

    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept
    {
        if (this == &other)
            return *this;

        delete m_ptr;
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;

        return *this;
    }

    void reset(T* new_ptr = nullptr)
    {
        delete m_ptr;
        m_ptr = new_ptr;
    }

    T* release()
    {
        T* tmp = m_ptr;
        m_ptr = nullptr;
        return tmp;
    }
    T& operator*()  const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    T* get()        const { return m_ptr; }

private:
    T* m_ptr { nullptr };
};
