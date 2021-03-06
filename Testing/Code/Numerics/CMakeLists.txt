##TODO Need to update to new statistics framework  SUBDIRS(Statistics)

SUBDIRS(FEM)
SUBDIRS(NeuralNetworks)

IF( NOT ITK_DISABLE_CXX_TESTING )
IF(ITK_BINARY_DIR)
  IF(TCL_TCLSH)
    ADD_TEST(PrintSelf-Numerics ${TCL_TCLSH}
             ${ITK_SOURCE_DIR}/Utilities/Dart/PrintSelfCheck.tcl
             ${ITK_SOURCE_DIR}/Code/Numerics)
  ENDIF(TCL_TCLSH)
ENDIF(ITK_BINARY_DIR)


SET(NUMERICS_TESTS ${CXX_TEST_PATH}/itkNumericsTests)
SET(NUMERICS_HEADER_TEST ${CXX_TEST_PATH}/itkNumericsHeaderTest)

ADD_TEST(itkAmoebaOptimizerTest ${NUMERICS_TESTS} itkAmoebaOptimizerTest)
ADD_TEST(itkCompositeValleyFunctionTest ${NUMERICS_TESTS} itkCompositeValleyFunctionTest)
ADD_TEST(itkConjugateGradientOptimizerTest ${NUMERICS_TESTS} itkConjugateGradientOptimizerTest)
ADD_TEST(itkCumulativeGaussianOptimizerTest ${NUMERICS_TESTS} itkCumulativeGaussianOptimizerTest)
ADD_TEST(itkExhaustiveOptimizerTest ${NUMERICS_TESTS} itkExhaustiveOptimizerTest)
ADD_TEST(itkFRPROptimizerTest ${NUMERICS_TESTS} itkFRPROptimizerTest)
ADD_TEST(itkGradientDescentOptimizerTest ${NUMERICS_TESTS} itkGradientDescentOptimizerTest)
ADD_TEST(itkLBFGSBOptimizerTest ${NUMERICS_TESTS} itkLBFGSBOptimizerTest)
ADD_TEST(itkLBFGSOptimizerTest ${NUMERICS_TESTS} itkLBFGSOptimizerTest)
ADD_TEST(itkLevenbergMarquardtOptimizerTest ${NUMERICS_TESTS} itkLevenbergMarquardtOptimizerTest)
ADD_TEST(itkMultivariateLegendrePolynomialTest ${NUMERICS_TESTS} itkMultivariateLegendrePolynomialTest)
ADD_TEST(itkNumericsHeaderTest ${NUMERICS_HEADER_TEST})
ADD_TEST(itkNumericsPrintTest ${NUMERICS_TESTS} itkNumericsPrintTest)
ADD_TEST(itkNumericsTest ${NUMERICS_TESTS} itkNumericsTest)
ADD_TEST(itkOptimizersHierarchyTest ${NUMERICS_TESTS} itkOptimizersHierarchyTest)
ADD_TEST(itkPowellOptimizerTest ${NUMERICS_TESTS} itkPowellOptimizerTest)
ADD_TEST(itkRegularStepGradientDescentOptimizerTest ${NUMERICS_TESTS} itkRegularStepGradientDescentOptimizerTest)
ADD_TEST(itkSymmetricEigenSystemTest ${NUMERICS_TESTS} itkSymmetricEigenSystemTest)
ADD_TEST(itkSPSAOptimizerTest ${NUMERICS_TESTS} itkSPSAOptimizerTest)
ADD_TEST(itkVersorRigid3DTransformOptimizerTest ${NUMERICS_TESTS} itkVersorRigid3DTransformOptimizerTest)
ADD_TEST(itkVersorTransformOptimizerTest ${NUMERICS_TESTS} itkVersorTransformOptimizerTest)

SET(Numerics_SRCS
itkAmoebaOptimizerTest.cxx
itkCompositeValleyFunctionTest.cxx
itkConjugateGradientOptimizerTest.cxx
itkCumulativeGaussianOptimizerTest.cxx
itkExhaustiveOptimizerTest.cxx
itkFRPROptimizerTest.cxx
itkGradientDescentOptimizerTest.cxx
itkLBFGSBOptimizerTest.cxx
itkLBFGSOptimizerTest.cxx
itkLevenbergMarquardtOptimizerTest.cxx
itkMultivariateLegendrePolynomialTest.cxx
itkNumericsPrintTest.cxx
itkNumericsTest.cxx
itkOptimizersHierarchyTest.cxx
itkPowellOptimizerTest.cxx
itkRegularStepGradientDescentOptimizerTest.cxx
itkSPSAOptimizerTest.cxx
itkSymmetricEigenSystemTest.cxx
itkVersorRigid3DTransformOptimizerTest.cxx
itkVersorTransformOptimizerTest.cxx
)

IF(ITK_OBJCXX_COMPILER_WORKS)
  SET(NUMERICS_OBJCXX_TEST ${CXX_TEST_PATH}/itkNumericsHeaderObjCxxTest)
  ADD_TEST(itkNumericsHeaderObjCxxTest ${NUMERICS_OBJCXX_TEST})
  ADD_EXECUTABLE(itkNumericsHeaderObjCxxTest itkNumericsHeaderObjCxxTest.mm)
  TARGET_LINK_LIBRARIES(itkNumericsHeaderObjCxxTest ITKNumerics ITKStatistics)
ENDIF(ITK_OBJCXX_COMPILER_WORKS)

ADD_EXECUTABLE(itkNumericsHeaderTest itkNumericsHeaderTest.cxx)
TARGET_LINK_LIBRARIES(itkNumericsHeaderTest ITKNumerics ITKStatistics)

ADD_EXECUTABLE(itkNumericsTests itkNumericsTests.cxx ${Numerics_SRCS})
TARGET_LINK_LIBRARIES(itkNumericsTests ITKNumerics ITKIO ITKStatistics)

ENDIF( NOT ITK_DISABLE_CXX_TESTING )


