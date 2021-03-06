/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkCorrespondingList.txx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkCorrespondingList_txx
#define __itkCorrespondingList_txx

#include "itkCorrespondingList.h"

namespace itk
{

/**
 * Constructor.
 */
template <typename TItemType, int VCliqueSize>
CorrespondingList<TItemType, VCliqueSize>
::CorrespondingList()
{
}

/**
 * Destructor.
 */
template <typename TItemType, int VCliqueSize>
CorrespondingList<TItemType, VCliqueSize>
::~CorrespondingList()
{
}

} // end namespace itk

#endif
