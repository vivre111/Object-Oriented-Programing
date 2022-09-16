#include <vector>

template <typename a, typename b> class Subject {
 public:
  std::vector<a> as;
	std::vector<b> bs;
	virtual void attach(int in)=0;
	};
