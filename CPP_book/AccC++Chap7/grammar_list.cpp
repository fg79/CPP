#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>
#include <map>
#include "url.h"
#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;
using std::map;
using std::vector;
using std::istream;
using std::domain_error;
using std::logic_error;

typedef list<string> Rule;
typedef list<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;


int nrand(int n)
{
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range");

	const int bucket_size = RAND_MAX / n;
	int r;

	do r = rand() / bucket_size;
	while (r >= n);

	return r;
}

//read a grammar from a give input stream
Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;

	// read the input
	while (getline(in, line)) {

		// split the input into words
		vector<string> entry1 = split(line);

		Rule entry;
		std::copy( entry1.begin(), entry1.end(), std::back_inserter( entry ) );

		Rule::const_iterator rule_start = entry.begin();
		rule_start++;
	
		Rule::const_iterator rule_end = entry.end();


		if (!entry.empty())
			// use the category to store the associated rule
			ret[*(entry.begin())].push_back(Rule(rule_start, rule_end));
	}
#if 0
	cout << endl << endl;

	Grammar::const_iterator it = ret.begin();

	for(Grammar::const_iterator it1 = ret.begin(); it1 != ret.end(); ++it1 ) 
	{
		cout << " " << it1->first;
#if 0
		for(Rule_collection::const_iterator it2 = (it1->second).begin(); it2 != (it1->second).end(); ++it2 ) 
		{
			cout << " " << it1->first;
			for(Rule::const_iterator it3 = (*it2).begin(); it3 != (*it2).end(); ++it3 ) 
				cout << " " << *it3;
			cout << endl;
		}
#endif				

		cout << endl;
	}
#endif

	return ret;
}

bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}
#if 0
<noun> cat
<noun> dog
<noun> bird
<noun-phrase> <noun>
<noun-phrase> <adjective> <noun-phrase>
<adjective> large
<adjective> brown
<adjective> absurd
<verb> jumps
<verbs> sits
<verbs> eats
<location> on the stairs
<location> wherever it wants
<location> on the couch
<sentence> the <noun-phrase> <verb> <location>
#endif

void gen_aux(const Grammar& g, const string& word, list<string>& ret)
{
	//cout << "gen_aux: word = " << word << endl;

	if (!bracketed(word)) {
		ret.push_back(word);
	} else {
		// locate the rule that corresponds to word
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");
		
		// fetch the set of possible rules
		const Rule_collection& c = it->second;

		Rule_collection::const_iterator it_entry = c.begin();

		int num_rand = nrand(c.size());

		for (int num = 0;  num < num_rand; ++num)
			++it_entry;

		// from which we select one at random
		const Rule& r = (*it_entry);
#if 0
			cout << "num_rand = " <<  num_rand << " RULE of word " << it->first << endl;
			for(Rule::const_iterator it3 = r.begin(); it3 != r.end(); ++it3 ) 
				cout << " " << *it3;
			cout << endl;
#endif

		// recursively expand the selected rule
		for(Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_aux(g, *i, ret);		
	}
}

list<string> gen_sentence(const Grammar& g)
{
	list<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;	
}

int main()
{
	srand ( time(NULL) );
#if 0
	for (int i=1; i<10; i++) {
		cout << "nrand(" << i << ")= " << nrand(i);
		cout << endl;
	}
	
	cout << endl;
#endif

	// generate the sentence
	list<string> sentence = gen_sentence(read_grammar(cin));

	// write the first word, if any
 	list<string>::const_iterator it = sentence.begin();
	if (!sentence.empty()) {
		cout << " " << *it;
		++it;
	}

	// write the rest of the words, each preceded by a space
	while(it != sentence.end()) {
		cout << ", " << *it;
		++it;
	}

	cout << endl;
	return 0;
}
