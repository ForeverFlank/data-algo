void replace(const T& x, list<T>& y)
{
    auto it = begin();
    while (it != end())
    {
        if (*it == x)
        {
            it = erase(it);
            for (auto &item : y)
            {
                insert(it, item);
            }
        }
        else
        {
            it++;
        }
    }
}
