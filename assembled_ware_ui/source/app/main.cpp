/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 24-05-2016
///		Date update	: 24-05-2016
///		Comment		:
/// ============================================================================
#include "application.h"
#include "main_window.h"

/// ----------------------------------------------------------------------------
///	main( int argc, char *argv[] )
/// ----------------------------------------------------------------------------
int main( int argc, char *argv[] )
{
    assembled_ware::application app( argc, argv );

    assembled_ware::main_window w;
    w.show( );

    return app.exec( );
}
