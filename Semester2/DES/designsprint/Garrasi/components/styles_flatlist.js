import { StyleSheet } from 'react-native'

export const info_list = StyleSheet.create({
  profileImgContainer: {
      height: 4,
      width: 4,
      borderRadius: 2,
    },
    profileImg: {
      height: 4,
      width: 4,
      borderRadius: 2,
    },
    container: {
      flex: 1,
      flexDirection: 'row',
    },
})

export const reaction_bar = StyleSheet.create({
    container: {
      flex: 1,
      flexDirection: 'row',
    },
})

export const description_space = StyleSheet.create({
    container: {
      flex: 1,
      flexDirection: 'column',
    },
    comments: {
      marginTop: 5,
      color: '#5A5A5A',
    },
})