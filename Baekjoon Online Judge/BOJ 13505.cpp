#include <cstdio>

struct Trie {
	Trie *zr, *on;
	Trie() { zr = on = nullptr; }
	~Trie()
	{
		if (zr != nullptr) delete zr;
		if (on != nullptr) delete on;
	}
};

int main()
{
	int n, v;
	scanf("%d", &n);

	Trie *p = nullptr, *root = new Trie;
	int max = 0;
	while (n--)
	{
		scanf("%d", &v);
		
		p = root;

		//update max
		int bit = 29, val = 0;
		while (1)
		{
			if (((v >> bit) & 1) == 0)
			{
				if (p->on != nullptr)
				{
					val = (val << 1) | 1;
					p = p->on;
				}
				else if (p->zr != nullptr)
				{
					val <<= 1;
					p = p->zr;
				}
				else break;
			}
			else
			{
				if (p->zr != nullptr)
				{
					val = (val << 1) | 1;
					p = p->zr;
				}
				else if (p->on != nullptr)
				{
					val <<= 1;
					p = p->on;
				}
				else break;
			}

			--bit;
		}

		max = max < val ? val : max;

		//insert v
		p = root;
		bit = 29;
		while (bit >= 0)
		{
			if (((v >> bit) & 1) == 0)
			{
				if (p->zr != nullptr) p = p->zr;
				else
				{
					Trie *next = new Trie;
					p->zr = next;
					p = p->zr;
				}
			}
			else
			{
				if (p->on != nullptr) p = p->on;
				else
				{
					Trie *next = new Trie;
					p->on = next;
					p = p->on;
				}
			}

			--bit;
		}
	}

	printf("%d", max);

	return 0;
}