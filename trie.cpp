#include <vector>
#include <string>
#include <cassert>

// Trie from Competetive Programming 4. Book 2. Page 339.
namespace trie
{
	struct vertex
	{
		char alphabet;
		bool exist;
		std::vector<vertex *> child;
		vertex(char a): alphabet(a), exist(false)
		{
			child.assign(26, NULL);
		}
	};

	class Trie
	{
		private:
			vertex* root;
			const char first_letter = 'a';
		public:
			Trie()
			{
				root = new vertex('!');
			}

			void insert(const std::string &word)
			{
				vertex *cur = root;
				for (const auto &i : word)
				{
					int alpha_num = i - first_letter;
					if (cur->child[alpha_num] == NULL)
					{
						cur->child[alpha_num] = new vertex(word[i]);
					}
					cur = cur->child[alpha_num];
				}
				cur->exist = true;
			}

			bool search(const std::string &word)
			{
				vertex *cur = root;
				for (const auto &i : word)
				{
					int alpha_num = i - first_letter;
					if (cur->child[alpha_num] == NULL)
					{
						return false;
					}
					cur = cur->child[alpha_num];
				}
				return cur->exist;
			}

			bool starts_with(const std::string &word)
			{
				vertex *cur = root;
				for (const auto &i : word)
				{
					int alpha_num = i - first_letter;
					if (cur->child[alpha_num] == NULL)
					{
						return false;
					}
					cur = cur->child[alpha_num];
				}
				return true;
			}
	};
}

int main()
{
	trie::Trie trie;

	trie.insert("abcdef");
	trie.insert("bababc");
	trie.insert("abbcde");
	trie.insert("abcccd");
	trie.insert("aabcdd");
	trie.insert("abcdee");
	trie.insert("ababab");

	assert(trie.search("abcccd") == true);
	assert(trie.search("aaaaaa") == false);
	assert(trie.search("bbbbbb") == false);
	assert(trie.search("abc") == false);

	return 0;
}
