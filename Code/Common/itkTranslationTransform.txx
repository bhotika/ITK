/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkTranslationTransform.txx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkTranslationTransform_txx
#define __itkTranslationTransform_txx

#include "itkTranslationTransform.h"
#include "itkMath.h"


namespace itk
{

// Constructor with default arguments
template<class TScalarType, unsigned int NDimensions>
TranslationTransform<TScalarType, NDimensions>::
TranslationTransform():Superclass(SpaceDimension,ParametersDimension)
{
  m_Offset.Fill( 0 );

  // The Jacobian of this transform is constant.
  // Therefore the m_Jacobian variable can be 
  // initialized here and be shared among all the threads.
  this->m_Jacobian.Fill( 0.0 );

  for(unsigned int i=0; i<NDimensions; i++)
    {
    this->m_Jacobian(i,i) = 1.0;
    }

}
    

// Destructor
template<class TScalarType, unsigned int NDimensions>
TranslationTransform<TScalarType, NDimensions>::
~TranslationTransform()
{
  return;
}


// Set the parameters
template <class TScalarType, unsigned int NDimensions>
void
TranslationTransform<TScalarType, NDimensions>
::SetParameters( const ParametersType & parameters )
{
  typedef typename ParametersType::ValueType  ParameterValueType;
  bool modified = false;
  for( unsigned int i=0; i<SpaceDimension; i++ )
    {
    if (m_Offset[i] != parameters[i])
      {
      m_Offset[i] = parameters[i];
      modified = true;
      }
    }
  if (modified)
    {
    this->Modified();
    }
}

// Get the parameters
template <class TScalarType, unsigned int NDimensions>
const typename TranslationTransform<TScalarType, NDimensions>::ParametersType &
TranslationTransform<TScalarType, NDimensions>
::GetParameters( void ) const
{
  for( unsigned int i=0; i<SpaceDimension; i++ )
    {
    this->m_Parameters[i] = this->m_Offset[i];
    }  
  return this->m_Parameters;
}

// Print self
template<class TScalarType, unsigned int NDimensions>
void
TranslationTransform<TScalarType, NDimensions>::
PrintSelf(std::ostream &os, Indent indent) const
{
  Superclass::PrintSelf(os,indent);
  
  os << indent << "Offset: " << m_Offset << std::endl;
}


// Compose with another affine transformation
template<class TScalarType, unsigned int NDimensions>
void
TranslationTransform<TScalarType, NDimensions>::
Compose(const Self * other, bool )
{
  this->Translate(other->m_Offset);
  return;
}


// Compose with a translation
template<class TScalarType, unsigned int NDimensions>
void
TranslationTransform<TScalarType, NDimensions>::
Translate(const OutputVectorType &offset, bool )
{
  ParametersType newOffset(SpaceDimension);
  for( unsigned int i=0; i<SpaceDimension; i++ )
    {
    newOffset[i] = m_Offset[i] + offset[i];
    }
  this->SetParameters (newOffset);
  return;
}

// Transform a point
template<class TScalarType, unsigned int NDimensions>
typename TranslationTransform<TScalarType, NDimensions>::OutputPointType
TranslationTransform<TScalarType, NDimensions>::
TransformPoint(const InputPointType &point) const 
{
  return point + m_Offset;
}


// Transform a vector
template<class TScalarType, unsigned int NDimensions>
typename TranslationTransform<TScalarType, NDimensions>::OutputVectorType
TranslationTransform<TScalarType, NDimensions>::
TransformVector(const InputVectorType &vect) const 
{
  return  vect;
}


// Transform a vnl_vector_fixed
template<class TScalarType, unsigned int NDimensions>
typename TranslationTransform<TScalarType, NDimensions>::OutputVnlVectorType
TranslationTransform<TScalarType, NDimensions>::
TransformVector(const InputVnlVectorType &vect) const 
{
  return  vect;
}


// Transform a CovariantVector
template<class TScalarType, unsigned int NDimensions>
typename TranslationTransform<TScalarType, NDimensions>::OutputCovariantVectorType
TranslationTransform<TScalarType, NDimensions>::
TransformCovariantVector(const InputCovariantVectorType &vect) const 
{
  return  vect;
}

// return an inverse transformation
template<class TScalarType, unsigned int NDimensions>
bool
TranslationTransform<TScalarType, NDimensions>::
GetInverse( Self* inverse) const
{
  if(!inverse)
    {
    return false;
    }

  inverse->m_Offset   = - m_Offset;
  return true;
}

// Return an inverse of this transform
template<class TScalarType, unsigned int NDimensions>
typename TranslationTransform<TScalarType, NDimensions>::InverseTransformBasePointer
TranslationTransform<TScalarType, NDimensions>
::GetInverseTransform() const
{
  Pointer inv = New();
  return GetInverse(inv) ? inv.GetPointer() : NULL;
}

// Compute the Jacobian in one position 
template<class TScalarType, unsigned int NDimensions>
const typename TranslationTransform<TScalarType, NDimensions>::JacobianType & 
TranslationTransform< TScalarType, NDimensions >::
GetJacobian( const InputPointType & ) const
{
  // the Jacobian is constant for this transform, and it has already been
  // initialized in the constructor, so we just need to return it here.
  return this->m_Jacobian;
}

// Set the parameters for an Identity transform of this class
template<class TScalarType, unsigned int NDimensions>
void
TranslationTransform<TScalarType, NDimensions>::
SetIdentity()
{
  m_Offset.Fill( 0.0 );
}
 
  
} // namespace

#endif
