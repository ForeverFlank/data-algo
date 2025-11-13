void splitList(list<T>& list1, list<T>& list2)
{
	size_t half_size = (mSize + 1) / 2;
	auto p = mHeader->next;
	for (size_t i = 0; i < half_size; i++)
	{
		p = p->next;
	}
	
	list1.mHeader->prev->next = mHeader->next;
	mHeader->next->prev = list1.mHeader->prev;

	list1.mHeader->prev = p->prev;
	p->prev->next = list1.mHeader;


	list2.mHeader->prev->next = p;
	p->prev = list2.mHeader->prev;

	list2.mHeader->prev = mHeader->prev;
	mHeader->prev->next = list2.mHeader;


	list1.mSize += half_size;
	list2.mSize += mSize - half_size;

	mSize = 0;
	mHeader->prev = mHeader;
	mHeader->next = mHeader;
}
