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

    T& operator*()  const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    T* get() const { return m_ptr; }

private:
    T* m_ptr;
};
