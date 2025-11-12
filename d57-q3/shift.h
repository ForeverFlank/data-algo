void shift(int k)
{
	int size = (int)mSize;
	k = ((k % size) + size) % size;
	if (k == 0) return;

	node *p = mHeader;
	for (size_t i = 0; i < k; i++, p = p->next);
	
	mHeader->prev->next = mHeader->next;
	mHeader->next->prev = mHeader->prev;

	mHeader->next = p->next;
	p->next->prev = mHeader;

	p->next = mHeader;
	mHeader->prev = p;
}
