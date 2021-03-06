/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    wrap_vnl_matrix_fixed_ref.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "vnl/vnl_matrix_fixed_ref.h"

#ifdef CABLE_CONFIGURATION
#include "wrap_VXLNumerics.h"

namespace _cable_
{
  const char* const group = ITK_WRAP_GROUP(vnl_matrix_fixed_ref);
  namespace wrappers
  {
    typedef vnl_matrix_fixed_ref<double,2,2>  vnl_matrix_fixed_ref_double_2_2;
    typedef vnl_matrix_fixed_ref<double,2,3>  vnl_matrix_fixed_ref_double_2_3;
    typedef vnl_matrix_fixed_ref<double,3,12> vnl_matrix_fixed_ref_double_3_12;
    typedef vnl_matrix_fixed_ref<double,3,3>  vnl_matrix_fixed_ref_double_3_3;
    typedef vnl_matrix_fixed_ref<double,3,4>  vnl_matrix_fixed_ref_double_3_4;
    typedef vnl_matrix_fixed_ref<double,4,3>  vnl_matrix_fixed_ref_double_4_3;
    typedef vnl_matrix_fixed_ref<double,4,4>  vnl_matrix_fixed_ref_double_4_4;
  }
}

void force_instantiate()
{
  using namespace _cable_::wrappers;
  sizeof(vnl_matrix_fixed_ref_double_2_2);
  sizeof(vnl_matrix_fixed_ref_double_2_3);
  sizeof(vnl_matrix_fixed_ref_double_3_12);
  sizeof(vnl_matrix_fixed_ref_double_3_3);
  sizeof(vnl_matrix_fixed_ref_double_3_4);
  sizeof(vnl_matrix_fixed_ref_double_4_3);
  sizeof(vnl_matrix_fixed_ref_double_4_4);
}

#endif
