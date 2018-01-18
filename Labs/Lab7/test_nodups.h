/***************************************************************************/
/*
 * TEST:  Lab 7 C
 */

START_TEST ( test_nodups_01 ) {
   
    node_t * h1 = NULL;
    
    ck_assert( !llist_nodups( &h1 ) );

    llist_free( &h1 );
}
END_TEST


START_TEST ( test_nodups_02 ) {
   
    node_t * h1 = NULL;


    llist_push( &h1, 15 );
    llist_push( &h1, 10 );
    llist_push( &h1, 10 );
    llist_push( &h1,  5 );

    ck_assert( llist_nodups( &h1 ) == 1 );
    ck_assert( llist_count( h1, 10 ) == 1 );
    ck_assert( llist_size( h1 ) == 3);
    

    llist_free( &h1 );
  

}
END_TEST

START_TEST ( test_nodups_03 ) {
   
    node_t * h1 = NULL;


    llist_push( &h1, 15 );
    llist_push( &h1, 10 );
    llist_push( &h1, 10 );
    llist_push( &h1, 10 );
    llist_push( &h1,  5 );

    ck_assert( llist_nodups( &h1 ) == 2 );
    ck_assert( llist_count( h1, 10 ) == 1 );
    ck_assert( llist_size( h1 ) == 3);


    llist_free( &h1 );
  

}
END_TEST
 
START_TEST ( test_nodups_04 ) {
   
    node_t * h1 = NULL;

    llist_push( &h1,  5 );
    llist_push( &h1,  5 );

    ck_assert( llist_nodups( &h1 ) == 1 );
    ck_assert( llist_count( h1, 5 ) == 1 );
    ck_assert( llist_size( h1 ) == 1);

    llist_free( &h1 );
  

}
END_TEST 
