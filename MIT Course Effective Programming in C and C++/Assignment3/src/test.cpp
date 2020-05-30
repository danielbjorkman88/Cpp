#include "list.h"
#include "apply.h"
#include "reduce.h"
#include <iostream>
# include <assert.h>


int main() {
  try {

    List olist{};



    unsigned int N = 10;
    for( size_t i = 0; i < N; ++i ) {
      olist.append( i );
    }
    olist.print();

    assert(N == olist.length());


    List olist2{};
    olist2 = olist;
    std::cout << "olist copied over to olist2" << std::endl;

    olist2.append( 5 );

		olist2.deleteAll( 0 );
		olist2.deleteAll( N );
		olist2.deleteAll( N - 1 );
    List list{olist2};

    std::cout << "value(0)=" << list.value( 0 ) << '\n';
    std::cout << "value(1)=" << list.value( 1 ) << '\n';
    std::cout << "value(" << list.length() - 1 << ")=" << list.value( list.length() - 1 ) << '\n';
    list = list;
    list.apply( SquareApply{} );
    std::cout << "apply^2 & reduce+: " << list.reduce( SumReduce{} ) << "\n";

    List blist{};
    blist.append( 0 );
    blist.deleteAll( 0 );
    assert(0 == blist.length());

    List clist{};
    clist.append( 0 );
    clist.append( 0 );
    clist.deleteAll( 0 );
    clist.deleteAll( 0 );
    clist.deleteAll( 1 );
    assert(0 == clist.length());

    olist.clear();
    olist.append( 0 );
    olist.append( 0 );
    olist.deleteAll( 0 );
    assert(0 == olist.length());

    olist.clear();
    olist.append( 0 );
    olist.append( 1 );
    olist.append( 2 );
    olist.insertBefore(10,2);
    olist.print();


    return 0;
  } catch( const std::exception &e ) {
    std::cerr << e.what() << "\n";









    return 1;
  }
}
