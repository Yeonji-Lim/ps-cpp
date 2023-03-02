-- 132204
-- 2022년 4월 13일 취소되지 않은 흉부외과(CS) 진료 예약 내역을 조회
-- 진료예약번호, 환자이름, 환자번호, 진료과코드, 의사이름, 진료예약일시
-- 진료예약일시를 기준으로 오름차순
SELECT A.APNT_NO, P.PT_NAME, P.PT_NO, D.MCDP_CD, D.DR_NAME, A.APNT_YMD
FROM PATIENT P
    JOIN APPOINTMENT A ON
    P.PT_NO = A.PT_NO
    JOIN DOCTOR D ON
    A.MDDR_ID = D.DR_ID
WHERE YEAR(A.APNT_YMD) = 2022 AND MONTH(A.APNT_YMD) = 4 AND DAY(A.APNT_YMD) = 13 
    AND A.APNT_CNCL_YN = 'N'
ORDER BY APNT_YMD

-- 59046
-- 이름이 Lucy, Ella, Pickle, Rogan, Sabrina, Mitty인 동물
-- 아이디와 이름, 성별 및 중성화 여부
SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
FROM ANIMAL_INS
WHERE NAME IN ('Lucy', 'Ella', 'Pickle', 'Rogan', 'Sabrina', 'Mitty')

-- 59047
-- 개
-- 이름에 'el'이 들어간다
-- 아이디와 이름을 조회
-- 이름 순으로 조회
-- 이름의 대소문자는 구분하지 않습니다.
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE LOWER(NAME) LIKE '%el%' AND ANIMAL_TYPE = 'Dog'
ORDER BY NAME

-- 59409
-- 동물의 아이디와 이름, 중성화 여부
-- 아이디 순으로 조회
-- 중성화가 되어있다면 'O', 아니라면 'X'
-- 중성화된 동물은 SEX_UPON_INTAKE 컬럼에 'Neutered' 또는 'Spayed'라는 단어가 들어있음
SELECT ANIMAL_ID, NAME,
    CASE SEX_UPON_INTAKE 
        WHEN SEX_UPON_INTAKE Like '%Neutered%' or SEX_UPON_INTAKE Like '%Spayed%' 
        THEN 'X' ELSE 'O' END AS 중성화
FROM ANIMAL_INS
ORDER BY ANIMAL_ID

-- CASE에 컬럼명을 안쓰면 THEN 절에 반대로 안써도 됨
SELECT ANIMAL_ID, NAME,
    CASE WHEN SEX_UPON_INTAKE Like '%Neutered%' or SEX_UPON_INTAKE Like '%Spayed%' 
        THEN 'O' ELSE 'X' END AS 중성화
FROM ANIMAL_INS
ORDER BY ANIMAL_ID

-- 59411
-- 입양을 간 동물 중, 보호 기간이 가장 길었던 동물 두 마리의 아이디와 이름을 조회
-- 보호 기간이 긴 순으로 조회
SELECT O.ANIMAL_ID, O.NAME
FROM ANIMAL_OUTS O
    JOIN ANIMAL_INS I ON O.ANIMAL_ID = I.ANIMAL_ID
ORDER BY DATEDIFF(O.DATETIME, I.DATETIME) DESC
LIMIT 2

-- 131529
-- 상품 카테고리 코드(PRODUCT_CODE 앞 2자리) 별 상품 개수를 출력
-- 상품 카테고리 코드를 기준으로 오름차순 정렬
SELECT SUBSTRING(PRODUCT_CODE, 1, 2) AS CATEGORY, COUNT(*) AS PRODUCTS
FROM PRODUCT
GROUP BY CATEGORY
ORDER BY CATEGORY

-- 131113
-- 주문 ID, 제품 ID, 출고일자, 출고여부
-- 5월 1일까지 출고완료로 이 후 날짜는 출고 대기로 미정이면 출고미정으로 출력
-- 결과는 주문 ID를 기준으로 오름차순 정렬
SELECT ORDER_ID, PRODUCT_ID, DATE_FORMAT(OUT_DATE, '%Y-%m-%d'),
    CASE WHEN OUT_DATE is NULL THEN '출고미정'
    WHEN DATEDIFF(OUT_DATE, '2022-05-01') <= 0 THEN '출고완료'
    ELSE '출고대기' END AS '출고여부'
FROM FOOD_ORDER
ORDER BY ORDER_ID
