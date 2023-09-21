#include <iostream>
#include <vector>
#include <functional>
#include <random>
#include <string>
#include <limits>

template<typename K, typename V>
struct HashEntry {
	K key;
	V value;
	HashEntry(K k, V v) : key(k), value(v) {}
};

template<typename K, typename V>
class HashMap {
public:
	HashMap(size_t, size_t, double);
	void insert(const K&, const V&);
	bool get(const K&, V&);
private:
	size_t size;
	size_t capacity;
	double loadFactor;
	size_t numHashFunctions;
	std::vector<std::vector<HashEntry<K, V>>> table;
	std::vector<std::function<size_t(const K&)>> hashFuncs;
	std::vector<uint32_t> seedValues;

	void setloadFacror(double);
	bool shouldResiaze();
	void resizeTable();
	size_t DJB2Hash(uint32_t, const K&);
	size_t FNV1aHash(uint32_t,const K&);
};

template<typename K, typename V>
HashMap<K, V>::HashMap(size_t cap, size_t numFunc, double lf)
	:capacity{cap}
	,numHashFunctions{numFunc}
	,loadFactor{lf}
{
	table.resize(capacity);
	hashFuncs.resize(numHashFunctions);

	std::random_device rd;
    for (size_t i = 0; i < numHashFunctions; ++i) {
        std::mt19937 gen(rd());
        std::uniform_int_distribution<uint32_t> dist(1, std::numeric_limits<uint32_t>::max());
        seedValues.push_back(dist(gen));
    }
    
    for (size_t i = 0; i < numHashFunctions; ++i) {
        hashFuncs[i] = std::bind(&HashMap::DJB2Hash, this, seedValues[i], std::placeholders::_1);
    }
}

template<typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {
	if(shouldResiaze()) resizeTable();
	size_t index = hashFuncs[0](key) % capacity;
	++size;
}

template<typename K, typename V>
bool HashMap<K, V>::get(const K& key, V& result) {
	size_t index = hashFuncs[0](key) % capacity;
	for(const auto& entry : table[index]) {
		if(entry.key == key) {
			result = entry.value;
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
void HashMap<K, V>::setloadFacror(double l) {
	loadFactor = l;
}

template<typename K, typename V>
bool HashMap<K, V>::shouldResiaze() {
	double currentLoadFactor = static_cast<double>(size) / capacity;
	return currentLoadFactor > loadFactor;
}

template<typename K, typename V>
void HashMap<K, V>::resizeTable() {
	size_t newCapacity = capacity * 2;
	std::vector<std::vector<HashEntry<K, V>>> newTable(newCapacity);

	for(const auto& bucket : table) {
		for(const auto& entry : bucket) {
			size_t index = hashFuncs[0](entry.key) % newCapacity;
			newTable[index].emplace_back(entry.key, entry.value);
		}
	}

	capacity = newCapacity;
	table = std::move(newTable);
}

template<typename K, typename V>
size_t HashMap<K, V>::DJB2Hash(uint32_t seed, const K& key) {
	size_t hash = seed;
	for(char c : key) {
		hash = ((hash << 5) + hash) + static_cast<size_t>(c);
	}
	return hash;
}

template<typename K, typename V>
size_t HashMap<K, V>::FNV1aHash(uint32_t seed, const K& key) {
	const size_t prime = 16777617; 
	size_t hash = seed;
	for(char c : key) {
		hash ^= static_cast<size_t>(c);
		hash *= prime;
	}
	return hash;
}

