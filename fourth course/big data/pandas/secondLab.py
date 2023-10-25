import pandas

path = 'G:/data/EAR_4MTH_SEX_ECO_CUR_NB_A.csv'

data = pandas.read_csv(path)
data = data[(data.ref_area != 'BLR') & (data.ref_area != 'ZWE')]
data_ref_area = pandas.read_csv('G:/data/ref_area_en.csv', index_col='ref_area')
data_ref_area = data_ref_area.rename(columns={' ref_area.label': 'ref_area_label'})
data = data.join(data_ref_area, on=['ref_area'])

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_M")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.max())

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_M")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.min())

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_M")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.mean())

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_M")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.median())

print('\n\n')


print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_F")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.max())

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_F")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.min())

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_F")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.mean())

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_F")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.median())


print('\n\n')

print(data[
    (data.classif1 == "ECO_ISIC2_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.max())

print(data[
    (data.classif1 == "ECO_ISIC2_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.min())

print(data[
    (data.classif1 == "ECO_ISIC2_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.mean())

print(data[
    (data.classif1 == "ECO_ISIC2_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.median())
