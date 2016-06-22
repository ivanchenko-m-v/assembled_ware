///$Header
///=============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 08-11-2010
///		Date update	: 20-06-2016
///		Comment		:
///=============================================================================
#include <QLineEdit>
#include <QPainter>

#include "delegate_line_edit.h"

namespace espira
{
namespace controls
{
///#############################################################################
///			class delegate_line_edit
///#############################################################################

	///=========================================================================
	///		CONSTRUCTORS/DESTRUCTOR
	///=========================================================================

	///-------------------------------------------------------------------------
	///	delegate_line_edit( )
	///-------------------------------------------------------------------------
	delegate_line_edit::delegate_line_edit( QObject *parent ) :
		QStyledItemDelegate( parent ),
		_alignment( Qt::AlignLeft | Qt::AlignVCenter )
	{
	}

	///-------------------------------------------------------------------------
	///	~delegate_line_edit( )
	///-------------------------------------------------------------------------
	delegate_line_edit::~delegate_line_edit( )
	{
	}

	///=========================================================================
	///		PROPERTIES
	///=========================================================================

	///=========================================================================
	///		OPERATORS
	///=========================================================================

	///=========================================================================
	///		FUNCTIONS
	///=========================================================================
	///-------------------------------------------------------------------------
	///	virtual
	///	createEditor( )
	///-------------------------------------------------------------------------
	QWidget* delegate_line_edit::createEditor(
									QWidget *parent,
									const QStyleOptionViewItem &/*option*/,
									const QModelIndex &/*index */
										   ) const
	{
		QLineEdit* editor = new QLineEdit( parent );
		editor->setFrame( false );
		editor->setAlignment( this->_alignment );

		return editor;
	}

	///-------------------------------------------------------------------------
	///	virtual
	///	setEditorData( )
	///-------------------------------------------------------------------------
	void delegate_line_edit::setEditorData(
										QWidget *editor,
										const QModelIndex &index
										  ) const
	{
		QString value = index.model( )->data(
											index, Qt::DisplayRole
											).toString( );

		QLineEdit* tedit = static_cast<QLineEdit*>( editor );
		tedit->setText( value );
	}

	///-------------------------------------------------------------------------
	///	virtual
	///	setEditorData( )
	///-------------------------------------------------------------------------
	void delegate_line_edit::setModelData(
									QWidget *editor, QAbstractItemModel *model,
									const QModelIndex &index
										 ) const
	{
		model->setData(
						index,
						static_cast<QLineEdit*>( editor ) -> text( ),
						Qt::EditRole
					  );
	}

	///-------------------------------------------------------------------------
	///	virtual
	///	updateEditorGeometry( )
	///-------------------------------------------------------------------------
	void delegate_line_edit::updateEditorGeometry(
											QWidget *editor,
											const QStyleOptionViewItem &option,
											const QModelIndex &/* index */
												 ) const
	{
		editor->setGeometry( option.rect );
	}

	///-------------------------------------------------------------------------
	///	virtual
	///	paint( ) (from QItemDelegate)
	///-------------------------------------------------------------------------
	/*
	void delegate_line_edit::paint(
									QPainter* painter,
									const QStyleOptionViewItem& option,
									const QModelIndex& index
								  ) const
	{
		//Отрисовка бэкграунда
		this->drawBackground( painter, option, index );
		//Отрисовка фокуса
		if( option.state & QStyle::State_Selected )
		{
			this -> drawFocus( painter, option, option.rect );
		}
		//Получение данных
		QString value = index.model( )->data(
												index,
												Qt::DisplayRole
											).toString( );
		//Отрисовка данных
		QPen pen( Qt::SolidLine );
		pen.setColor(
				!( option.state & QStyle::State_Selected )
					? option.palette.brush( QPalette::Foreground ).color( )
					: option.palette.brush( QPalette::HighlightedText ).color( )
					);
		painter -> setPen( pen );
		painter -> drawText(
							option.rect.adjusted( 4, 0, -4, 0 ),
							this -> _alignment,
							value
							);
	}
	*/
	///-------------------------------------------------------------------------
	///	virtual
	///	paint( ) (from QStyledItemDelegate)
	///-------------------------------------------------------------------------
	void delegate_line_edit::paint(
									QPainter* painter,
									const QStyleOptionViewItem& option,
									const QModelIndex& index
								  ) const
	{
		if( !index.isValid( ) )
		{
			return;
		}
		bool selected = option.state & QStyle::State_Selected;
		QPalette palette( option.palette );
		palette.setColor(
							QPalette::Active, QPalette::Window,
							selected ? option.palette.highlight( ).color( )
									 : option.palette.base( ).color( )
						);
		palette.setColor(
							QPalette::Active, QPalette::WindowText,
							selected ? option.palette.highlightedText( ).color( )
									 : option.palette.text( ).color( )
						);
						/*
		//Отрисовка бэкграунда
		this->drawBackground( painter, option, index );
		//Отрисовка фокуса
		if( option.state & QStyle::State_Selected )
		{
			this -> drawFocus( painter, option, option.rect );
		}
		*/
		//Получение данных
		QString value = index.model( )->data(
												index,
												Qt::DisplayRole
											).toString( );
		//Отрисовка данных
		QPen pen( Qt::SolidLine );
		pen.setColor(
				!( option.state & QStyle::State_Selected )
					? option.palette.brush( QPalette::Foreground ).color( )
					: option.palette.brush( QPalette::HighlightedText ).color( )
					);
		painter->save();
		painter -> setPen( pen );
		painter -> drawText(
							option.rect.adjusted( 4, 0, -4, 0 ),
							this -> _alignment,
							value
							);
		painter->restore();
	}
///#############################################################################

}//namespace controls

}//namespace espira
