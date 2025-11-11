#pragma once

template<class Item>
class heap_with_array{
    private:
    int count;
    Item heap[100001];

    public:
    void add_item(const Item & d);
    Item get_item();
    void delete_item();
};