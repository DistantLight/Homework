import pandas

path = 'G:/data/EAR_4MTH_SEX_ECO_CUR_NB_A.csv'

data = pandas.read_csv(path)
print(data)

print('Row count:'+ str(len(data)))
print(len(data.index))
print(data.shape[0])

print('Column count:')
print(data.shape[1])

(row_count, col_count) = data.shape
print('row count='+str(row_count)+ ", column count:"+ str(col_count))

print(data.head())

print(data[:10])

print(data[4:10])

print(data[4:12])

print(data.iloc[4])

print(type(data.iloc[4]))

print(data.iloc[4]['ref_area'])

print(data.iloc[4]['obs_value'])

print(data.iloc[4:12, 0:8])

print(type(data.iloc[4:12, 0:8]))

print(list(data.columns.values))

print(data.columns.values.tolist())

print(data['sex'])

print(type(data['sex']))

print(data['sex'].size)

print(data.sex.size)

print(data.sex.value_counts())

print(data['sex'].value_counts())

print(data.sex.value_counts()['SEX_T'])

print(data.ref_area.value_counts())

print(data['ref_area'].value_counts())

print(data[data.ref_area == "USA"])

print(data[data.ref_area == "RUS"])

data = data[['ref_area', 'sex', 'classif1', 'classif2', 'time', 'obs_value']]

print(data[data.ref_area =="RUS"])

print(data[data.ref_area =="RUS"].time.value_counts())

print(data[data.ref_area=="RUS"].time.value_counts().sort_index())

print(data[ (data.ref_area=="RUS") & (data.time == 2005)])

print(data.classif1.value_counts())
print(data.classif2.value_counts())

print(data[ (data.ref_area =="RUS")&
          (data.classif1 == "ECO_AGGREGATE_TOTAL")&
          ((data.time >= 2013) & (data.time <= 2015))])

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.max())

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.mean())

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.median())

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].sort_values(by='obs_value', ascending=False)[:50])

data = data[(data.ref_area != 'BLR') & (data.ref_area != 'ZWE')]

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.max())

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == " CUR_TYPE_USD")
].obs_value.min())

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.mean())

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].obs_value.median())

data_ref_area = pandas.read_csv('G:/data/ref_area_en.csv', index_col='ref_area')
print(data_ref_area[:10])

print(data_ref_area.columns.values.tolist())

data_ref_area = data_ref_area.rename(columns={' ref_area.label': 'ref_area_label'})
print(data_ref_area[:5])

data = data.join(data_ref_area, on=['ref_area'])
print(data[:5])

data = data[
    ['ref_area', 'ref_area_label', 'sex', 'classif1', 'classif2', 'time', 'obs_value']]
print(data)

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].sort_values(by='obs_value', ascending=False)[:20])

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")
].sort_values(by='obs_value', ascending=True)[:20])

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")&
    (data.time == 2019)
].sort_values(by='obs_value', ascending = False)[:20])

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.classif2 == "CUR_TYPE_USD")&
    (data.time == 2019)
].sort_values(by='obs_value', ascending=True)[:20])
