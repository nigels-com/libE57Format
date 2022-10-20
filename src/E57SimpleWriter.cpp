/*
 * Copyright (c) 2010 Stan Coleby (scoleby@intelisum.com)
 * Copyright (c) 2020 PTC Inc.
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "E57SimpleWriter.h"
#include "WriterImpl.h"

namespace e57
{

   // Note that this constructor is deprecated (see header).
   Writer::Writer( const ustring &filePath, const ustring &coordinateMetadata ) :
      Writer( filePath, WriterOptions{ {}, coordinateMetadata } )
   {
   }

   Writer::Writer( const ustring &filePath, const WriterOptions &options ) :
      impl_( new WriterImpl( filePath, options ) )
   {
   }

   bool Writer::IsOpen() const
   {
      return impl_->IsOpen();
   };

   bool Writer::Close()
   {
      return impl_->Close();
   };

   ImageFile Writer::GetRawIMF()
   {
      return impl_->GetRawIMF();
   }

   StructureNode Writer::GetRawE57Root()
   {
      return impl_->GetRawE57Root();
   };

   VectorNode Writer::GetRawData3D()
   {
      return impl_->GetRawData3D();
   };

   VectorNode Writer::GetRawImages2D()
   {
      return impl_->GetRawImages2D();
   };

   int64_t Writer::NewImage2D( Image2D &image2DHeader )
   {
      return impl_->NewImage2D( image2DHeader );
   };

   int64_t Writer::WriteImage2DData( int64_t imageIndex, Image2DType imageType, Image2DProjection imageProjection,
                                     void *pBuffer, int64_t start, int64_t count )
   {
      return impl_->WriteImage2DData( imageIndex, imageType, imageProjection, pBuffer, start, count );
   };

   int64_t Writer::NewData3D( Data3D &data3DHeader )
   {
      return impl_->NewData3D( data3DHeader );
   };

   CompressedVectorWriter Writer::SetUpData3DPointsData( int64_t dataIndex, size_t pointCount,
                                                         const Data3DPointsData &buffers )
   {
      return impl_->SetUpData3DPointsData( dataIndex, pointCount, buffers );
   }

   CompressedVectorWriter Writer::SetUpData3DPointsData( int64_t dataIndex, size_t pointCount,
                                                         const Data3DPointsData_d &buffers )
   {
      return impl_->SetUpData3DPointsData( dataIndex, pointCount, buffers );
   }

   bool Writer::WriteData3DGroupsData( int64_t dataIndex, int64_t groupCount, int64_t *idElementValue,
                                       int64_t *startPointIndex, int64_t *pointCount )
   {
      return impl_->WriteData3DGroupsData( dataIndex, groupCount, idElementValue, startPointIndex, pointCount );
   }

} // end namespace e57
