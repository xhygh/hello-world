
# set

c++ stl集合(Set)是一种包含已排序对象的关联容器。set/multiset会根据待定的排序准则，自动将元素排序。两者不同在于前者不允许元素重复，而后者允许。

1) 不能直接改变元素值，因为那样会打乱原本正确的顺序，要改变元素值必须先删除旧元素，则插入新元素

2) 不提供直接存取元素的任何操作函数，只能通过迭代器进行间接存取，而且从迭代器角度来看，元素值是常数

3) 元素比较动作只能用于型别相同的容器(即元素和排序准则必须相同)

## 成员函数


begin()--返回指向第一个元素的迭代器

clear()--清除所有元素

count()--返回某个值元素的个数

empty()--如果集合为空，返回true

end()--返回指向最后一个元素的下一个迭代器，所以整个set对象的区间是[begin(),end())

equal_range()--返回集合中与给定值相等的上下限的两个迭代器，分别表示第一个大于或等于给定关键值的元素和 第一个大于给定关键值的元素，这个返回值是一个pair类型，如果这一对定位器中哪个返回失败，就会等于end()的值。

erase(iter)--删除指定的元素

erase(begin,end)--删除[begin,end)间的val

erase(key_val)--删除值为key_val的元素

find()--返回一个指向被查找到元素的迭代器，如果没有返回end

get_allocator()--返回集合的分配器

insert(keyval)--在集合中插入元素keyval,返回pair<set<>::iterator,bool>，bool标志着插入是否成功，而iterator代表插入的位置，若key_value已经在set中，则iterator表示的key_value在set中的位置。

insert(begin,end)--将[begin,end)间的元素插入到当前set对象中。

lower_bound(keyval)--返回第一个大于（或等于）keyval的元素的迭代器

key_comp()--返回一个用于元素间值比较的函数

max_size()--返回集合能容纳的元素的最大限值

rbegin()--返回指向集合中最后一个元素的反向迭代器

rend()--返回指向集合中第一个元素的反向迭代器

size()--集合中元素的数目

swap()--交换两个集合变量

upper_bound(keyval)--返回第一个大于keyval的元素的迭代器

value_comp()--返回一个用于比较元素间的值的函数



# Tree

树适合范围查找，哈希适合等于查找。


## BST

二叉查找树的特点，lc < father,rc > father，中序遍历可以领节点从小到大排列。

# 删除remove和erase

  C++中的remove并不是真的删除，而是把目标元素转移到vector的末尾，如果要真正的删除需要配合erase
  原1,2,3,4,5
  remove(vec.begin(),vec.end(),3): 1,2,4,5,3
  erase(remove(vec.begin(),vec.end(),3),vec.end())
