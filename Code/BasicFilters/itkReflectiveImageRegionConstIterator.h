/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkReflectiveImageRegionConstIterator.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkReflectiveImageRegionConstIterator_h
#define __itkReflectiveImageRegionConstIterator_h

#include "itkImageConstIteratorWithIndex.h"

namespace itk
{

/** \class ReflectiveImageRegionConstIterator
 * \brief Multi-dimensional image iterator which only walks a region.
 * 
 * ReflectiveImageRegionConstIterator is a templated class to represent a
 * multi-dimensional iterator. ReflectiveImageRegionConstIterator is templated
 * over the image type.  ReflectiveImageRegionConstIterator is constrained to
 * walk only within the specified region.
 *
 * ReflectiveImageRegionConstIterator will perform two passes over the image
 * along each dimension. It is useful for algorithms that require to 
 * go back and forth (once) over the data. 
 *
 * By setting the BeginOffset and EndOffset parameters, you can
 * arrange for the starting point, when going forwards, to be
 * different from the ending point, when going backwards.  Along
 * dimension d, when going forwards the iterator traverses the
 * interval [BeginIndex[d]+BeginOffset[d], EndIndex[d]).  When going
 * back, it traverses the interval (EndIndex[d]-EndOffset[d],
 * BeginIndex[d]].  Setting both offsets to (1, ..., 1) enables the
 * DanielssonDistanceMapImageFilter to process the entire image,
 * rather than removing a one-pixel border.
 *
 * \sa DanielssonDistanceMapImageFilter
 *
 * \ingroup Iterators 
 */
template<typename TImage>
class ITK_EXPORT ReflectiveImageRegionConstIterator : public ImageConstIteratorWithIndex<TImage>
{
public:
  /** Standard class typedefs. */
  typedef ReflectiveImageRegionConstIterator   Self;
  typedef ImageConstIteratorWithIndex<TImage>  Superclass;

  /** Index typedef support. While this was already typdef'ed in the superclass
   * it needs to be redone here for this subclass to compile properly with gcc.
   * Note that we have to rescope Index back to itk::Index to that is it not
   * confused with ImageIterator::Index. */
  typedef typename TImage::IndexType  IndexType;

  /** Image typedef support. While this was already typdef'ed in the superclass
   * it needs to be redone here for this subclass to compile properly with gcc.
   * Note that we have to rescope Image back to itk::Image to that is it not
   * confused with ImageIterator::Image. */
  typedef TImage ImageType;

  /** PixelContainer typedef support. Used to refer to the container for
   * the pixel data. While this was already typdef'ed in the superclass
   * it needs to be redone here for this subclass to compile properly 
   * with gcc. */
  typedef typename TImage::PixelContainer  PixelContainer;
  typedef typename PixelContainer::Pointer PixelContainerPointer;

  /** Region typedef support. While this was already typdef'ed in the
   * superclass it needs to be redone here for this subclass to compile
   * properly with gcc.  Note that we have to rescope Region back to
   * itk::ImageRegion so that is it not confused with
   * ImageIterator::Index. */
  typedef typename TImage::RegionType RegionType;

  /** Type of the Offset taken from the image.  These typedefs are
   * duplicated from the superclass for gcc support. */
  typedef typename TImage::OffsetType           OffsetType;
  typedef typename OffsetType::OffsetValueType  OffsetValueType;

  /** Default constructor. Needed since we provide a cast constructor. */
  ReflectiveImageRegionConstIterator();
  
  /** Default destructor.  */
  ~ReflectiveImageRegionConstIterator() {};
  
  /** Constructor establishes an iterator to walk a particular image and a
   * particular region of that image. */
  ReflectiveImageRegionConstIterator( TImage *ptr, const RegionType& region );

  /** Copy Constructor. The copy constructor is provided to make sure the
   * handle to the image is properly reference counted. */
  ReflectiveImageRegionConstIterator( const Self& it );
   

  /** Constructor that can be used to cast from an ImageIterator to an
   * ReflectiveImageRegionConstIterator. Many routines return an
   * ImageIterator but for a particular task, you may want an
   * ReflectiveImageRegionConstIterator.  Rather than provide
   * overloaded APIs that return different types of Iterators, itk
   * returns ImageIterators and uses constructors to cast from * an
   * ImageIterator to a ReflectiveImageRegionConstIterator.  */
  ReflectiveImageRegionConstIterator(const ImageConstIteratorWithIndex<TImage> &it);

  /** operator= is provided to make sure the handle to the image is properly
   * reference counted. */
  Self &operator=(const Self& it);

  bool IsReflected(unsigned int) const;

  /** Increment (prefix) the fastest moving dimension of the iterator's index.
   * This operator will constrain the iterator within the region (i.e. the
   * iterator will automatically wrap from the end of the row of the region
   * to the beginning of the next row of the region) up until the iterator
   * tries to moves past the last pixel of the region.  Here, the iterator
   * will be set to be one pixel past the end of the region.
   * \sa operator++(int) */
  Self & operator++();

  /** Move an iterator to the beginning of the region. */
  void GoToBegin(void);

  /** Is the iterator at the beginning of the region? */
  bool IsAtBegin(void) const
    {
    return !this->m_Remaining;
    }

  /** Set the begin offset.  Forward iteration starts at this offset
   * from the current region.  */
  void SetBeginOffset(const OffsetType& offset)
    { m_BeginOffset = offset; }

  /** Set the end offset.  Reverse iteration starts at this offset
   * from the current region.  */
  void SetEndOffset(const OffsetType& offset)
    { m_EndOffset = offset; }

  /** Get the begin offset.  Forward iteration starts at this offset
   * from the current region.  */
  OffsetType GetBeginOffset(const OffsetType& offset)
    { return m_BeginOffset; }

  /** Get the end offset.  Reverse iteration starts at this offset
   * from the current region.  */
  OffsetType GetEndOffset(const OffsetType& offset)
    { return m_EndOffset; }

  /** Fill both offsets with a single value.  */
  void FillOffsets(const OffsetValueType &value);

private:
  bool       m_IsFirstPass[TImage::ImageDimension];
  OffsetType m_BeginOffset;
  OffsetType m_EndOffset;
  
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkReflectiveImageRegionConstIterator.txx"
#endif

#endif
