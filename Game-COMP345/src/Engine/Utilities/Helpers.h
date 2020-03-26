#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

namespace utilities
{
	class Helpers
	{
	private:
		Helpers() {}
	public:
		static int mod(int num, int div);
	};
}

