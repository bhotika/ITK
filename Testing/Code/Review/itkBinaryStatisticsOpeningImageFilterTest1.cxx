/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkBinaryStatisticsOpeningImageFilterTest1.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkSimpleFilterWatcher.h"

#include "itkBinaryStatisticsOpeningImageFilter.h"

#include "itkTestingMacros.h"

int itkBinaryStatisticsOpeningImageFilterTest1(int argc, char * argv[])
{

  if( argc != 10 )
    {
    std::cerr << "Usage: " << argv[0] << " input feature output";
    std::cerr << " foreground background lambda";
    std::cerr << "reverseOrdering connectivity attribute" << std::endl;
    return EXIT_FAILURE;
    }

  const unsigned int dim = 2;
  
  typedef itk::Image< unsigned char, dim > IType;

  typedef itk::ImageFileReader< IType > ReaderType;
  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName( argv[1] );

  ReaderType::Pointer reader2 = ReaderType::New();
  reader2->SetFileName( argv[2] );

  typedef itk::BinaryStatisticsOpeningImageFilter< IType, IType > BinaryOpeningType;
  BinaryOpeningType::Pointer opening = BinaryOpeningType::New();
  
  opening->SetInput( reader->GetOutput() );
 
  //testing get/set ForegroundValue macro
  int ForegroundValue = ( atoi(argv[4]) );
  opening->SetForegroundValue( ForegroundValue );
  TEST_SET_GET_VALUE( ForegroundValue, opening->GetForegroundValue() );

  //testing get/set BackgroundValue macro
  int BackgroundValue = ( atoi(argv[5]) );
  opening->SetBackgroundValue( BackgroundValue );
  TEST_SET_GET_VALUE( BackgroundValue, opening->GetBackgroundValue() );

  //testing get and set macros for Lambda 
  double lambda = atof( argv[6] );
  opening->SetLambda( lambda );
  TEST_SET_GET_VALUE( lambda , opening->GetLambda() );

  //testing boolean macro for ReverseOrdering
  opening->ReverseOrderingOn();
  TEST_SET_GET_VALUE( true, opening->GetReverseOrdering() ); 

  opening->ReverseOrderingOff();
  TEST_SET_GET_VALUE( false, opening->GetReverseOrdering() );

  //testing get and set macros or ReverseOrdering 
  bool reverseOrdering = atoi( argv[7] );
  opening->SetReverseOrdering( reverseOrdering );
  TEST_SET_GET_VALUE( reverseOrdering , opening->GetReverseOrdering() ); 

  //testing boolean macro for FullyConnected
  opening->FullyConnectedOn();
  TEST_SET_GET_VALUE( true, opening->GetFullyConnected() ); 

  opening->FullyConnectedOff();
  TEST_SET_GET_VALUE( false, opening->GetFullyConnected() );

  //testing get and set macros or FullyConnected 
  bool fullyConnected = atoi( argv[8] );
  opening->SetFullyConnected( fullyConnected );
  TEST_SET_GET_VALUE( fullyConnected , opening->GetFullyConnected() ); 

  //testing get and set macros for Attribute 
  BinaryOpeningType::AttributeType attribute = atoi( argv[9] );
  opening->SetAttribute( attribute );
  TEST_SET_GET_VALUE( attribute, opening->GetAttribute() );
 
  itk::SimpleFilterWatcher watcher(opening, "filter");

  typedef itk::ImageFileWriter< IType > WriterType;
  WriterType::Pointer writer = WriterType::New();
  writer->SetInput( opening->GetOutput() );
  writer->SetFileName( argv[3] );
  writer->UseCompressionOn();
  
  TRY_EXPECT_NO_EXCEPTION( writer->Update() );

  std::cout << "Test Complete!" << std::endl;

  return EXIT_SUCCESS;
}
