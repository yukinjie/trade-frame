/************************************************************************
 * Copyright(c) 2010, One Unified. All rights reserved.                 *
 *                                                                      *
 * This file is provided as is WITHOUT ANY WARRANTY                     *
 *  without even the implied warranty of                                *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                *
 *                                                                      *
 * This software may not be used nor distributed without proper license *
 * agreement.                                                           *
 *                                                                      *
 * See the file LICENSE.txt for redistribution information.             *
 ************************************************************************/

// OUSqlite Library
// was going to be pimpl, but couldn't, as templates are in use, no 'export' keyword
// includes are a bit messy, a compendium of ousql/session, ousql/sessionimpl, and this session file
// maybe using Spirit::Phoenix tuplies will get me out of this mess?

#include <OUSQL/Session.h>
#include <OUSQL/SessionImpl.h>

#include "ISqlite3.h"

namespace ou {
namespace db {

class CSessionImplCustom: public CSessionImpl<ISqlite3> {
public:
  CSessionImplCustom( void ): CSessionImpl<ISqlite3>() {};
  ~CSessionImplCustom( void ) {};
protected:
private:
};

template<class F> 
void CSession::Bind( QueryFields<F>& qf ) {
  pImpl->Bind<F>( qf );
}

template<class F> 
void CSession::Bind( typename QueryFields<F>::pQueryFields_t pQuery ) {
  pImpl->Bind<F>( pQuery );
}

template<class F, class C> 
void CSession::Columns( typename QueryFields<F>::pQueryFields_t pQuery, C& columns ) {
  pImpl->Columns<F,C>( pQuery, columns );
}

template<class F> 
QueryFields<F>& CSession::RegisterTable( const std::string& sTableName ) {
  return pImpl->RegisterTable<F>( sTableName );
}

template<class F> 
Query<F>& CSession::Insert( F& f ) {
  return pImpl->Insert<F>( f );
}

template<class F> 
Query<F>& CSession::Update( F& f ) {
  return pImpl->Update<F>( f );
}

template<class F> 
Query<F>& CSession::Delete( F& f ) {
  return pImpl->Delete<F>( f );
}

template<class F> 
Query< F>& CSession::SQL( const std::string& sSqlQuery, F& f ) {
  return pImpl->SQL<F>( sSqlQuery, f );
}

template<class F> 
Query< F>& CSession::SQL( const std::string& sSqlQuery ) {
  return pImpl->SQL<F>( sSqlQuery );
}

template<class F> 
void CSession::MapRowDefToTableName( const std::string& sTableName ) {
  pImpl->MapRowDefToTableName<F>( sTableName );
}



} // db
} // ou