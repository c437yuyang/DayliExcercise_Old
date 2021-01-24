void *memcpy(void *pDst, const void *pSrc, size_t size)
{
	if (pDst == nullptr || pSrc == nullptr)
		return nullptr;

	if (pDst == pSrc)
		return pDst;

	const char* pSrcCh = static_cast<const char*>(pSrc);
	char *pDstCh = static_cast<char *>(pDst);
	if (pSrcCh > pDstCh)
		while (size--)
			*pDstCh++ = *pSrcCh++;
	else
		while (size--)
			*(pDstCh + size) = *(pSrcCh + size);
	return pDst;
}